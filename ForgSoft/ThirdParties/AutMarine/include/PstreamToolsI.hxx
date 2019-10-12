#pragma once
namespace AutLib
{

	template <class T, class CombineOp>
	void PstreamTools::combineGather
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const CombineOp& cop
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				if (contiguous<T>())
				{
					T value;
					IPstream::read
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<char*>(&value),
						sizeof(T)
					);

					if (Pstream::debug > 1)
					{
						Pout << " received from "
							<< belowID << " data:" << value << endl;
					}

					cop(Value, value);
				}
				else
				{
					IPstream fromBelow(Pstream::scheduled, belowID);
					T value(fromBelow);

					if (Pstream::debug > 1)
					{
						Pout << " received from "
							<< belowID << " data:" << value << endl;
					}

					cop(Value, value);
				}
			}

			// Send up Value
			if (myComm.above() != -1)
			{
				if (Pstream::debug > 1)
				{
					Pout << " sending to " << myComm.above()
						<< " data:" << Value << endl;
				}

				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<const char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					OPstream toAbove(Pstream::scheduled, myComm.above());
					toAbove << Value;
				}
			}
		}
	}

	template <class T, class CombineOp>
	void PstreamTools::combineGather(T& Value, const CombineOp& cop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			combineGather(Pstream::linearCommunication(), Value, cop);
		}
		else
		{
			combineGather(Pstream::treeCommunication(), Value, cop);
		}
	}


	template <class T>
	void PstreamTools::combineScatter(const List<Pstream::commsStruct>& comms, T& Value)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from up
			if (myComm.above() != -1)
			{
				if (contiguous<T>())
				{
					IPstream::read
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					IPstream fromAbove(Pstream::scheduled, myComm.above());
					Value = T(fromAbove);
				}

				if (Pstream::debug > 1)
				{
					Pout << " received from "
						<< myComm.above() << " data:" << Value << endl;
				}
			}

			// Send to my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				if (Pstream::debug > 1)
				{
					Pout << " sending to " << belowID << " data:" << Value << endl;
				}

				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<const char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					OPstream toBelow(Pstream::scheduled, belowID);
					toBelow << Value;
				}
			}
		}
	}


	template <class T>
	void PstreamTools::combineScatter(T& Value)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			combineScatter(Pstream::linearCommunication(), Value);
		}
		else
		{
			combineScatter(Pstream::treeCommunication(), Value);
		}
	}


	// Same thing but for whole list at a time
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	template <class T, class CombineOp>
	void PstreamTools::listCombineGather
	(
		const List<Pstream::commsStruct>& comms,
		List<T>& Values,
		const CombineOp& cop
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				if (contiguous<T>())
				{
					List<T> receivedValues(Values.size());

					IPstream::read
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<char*>(receivedValues.begin()),
						receivedValues.byteSize()
					);

					if (Pstream::debug > 1)
					{
						Pout << " received from "
							<< belowID << " data:" << receivedValues << endl;
					}

					for (label i = 0; i < (Values).size(); i++)
					{
						cop(Values[i], receivedValues[i]);
					}
				}
				else
				{
					IPstream fromBelow(Pstream::scheduled, belowID);
					List<T> receivedValues(fromBelow);

					if (Pstream::debug > 1)
					{
						Pout << " received from "
							<< belowID << " data:" << receivedValues << endl;
					}

					for (label i = 0; i < (Values).size(); i++)
					{
						cop(Values[i], receivedValues[i]);
					}
				}
			}

			// Send up Value
			if (myComm.above() != -1)
			{
				if (Pstream::debug > 1)
				{
					Pout << " sending to " << myComm.above()
						<< " data:" << Values << endl;
				}

				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<const char*>(Values.begin()),
						Values.byteSize()
					);
				}
				else
				{
					OPstream toAbove(Pstream::scheduled, myComm.above());
					toAbove << Values;
				}
			}
		}
	}


	template <class T, class CombineOp>
	void PstreamTools::listCombineGather(List<T>& Values, const CombineOp& cop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			listCombineGather(Pstream::linearCommunication(), Values, cop);
		}
		else
		{
			listCombineGather(Pstream::treeCommunication(), Values, cop);
		}
	}


	template <class T>
	void PstreamTools::listCombineScatter
	(
		const List<Pstream::commsStruct>& comms,
		List<T>& Values
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from up
			if (myComm.above() != -1)
			{
				if (contiguous<T>())
				{
					IPstream::read
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<char*>(Values.begin()),
						Values.byteSize()
					);
				}
				else
				{
					IPstream fromAbove(Pstream::scheduled, myComm.above());
					fromAbove >> Values;
				}

				if (Pstream::debug > 1)
				{
					Pout << " received from "
						<< myComm.above() << " data:" << Values << endl;
				}
			}

			// Send to my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				if (Pstream::debug > 1)
				{
					Pout << " sending to " << belowID << " data:" << Values << endl;
				}

				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<const char*>(Values.begin()),
						Values.byteSize()
					);
				}
				else
				{
					OPstream toBelow(Pstream::scheduled, belowID);
					toBelow << Values;
				}
			}
		}
	}


	template <class T>
	void PstreamTools::listCombineScatter(List<T>& Values)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			listCombineScatter(Pstream::linearCommunication(), Values);
		}
		else
		{
			listCombineScatter(Pstream::treeCommunication(), Values);
		}
	}




	// Same thing but for sparse list (map)
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	template <class Container, class CombineOp>
	void PstreamTools::mapCombineGather
	(
		const List<Pstream::commsStruct>& comms,
		Container& Values,
		const CombineOp& cop
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				IPstream fromBelow(Pstream::scheduled, belowID);
				Container receivedValues(fromBelow);

				if (Pstream::debug > 1)
				{
					Pout << " received from "
						<< belowID << " data:" << receivedValues << endl;
				}

				for
					(
						typename Container::const_iterator slaveIter =
						receivedValues.begin();
						slaveIter != receivedValues.end();
						++slaveIter
						)
				{
					typename Container::iterator
						masterIter = Values.find(slaveIter.key());

					if (masterIter != Values.end())
					{
						cop(masterIter(), slaveIter());
					}
					else
					{
						Values.insert(slaveIter.key(), slaveIter());
					}
				}
			}

			// Send up Value
			if (myComm.above() != -1)
			{
				if (Pstream::debug > 1)
				{
					Pout << " sending to " << myComm.above()
						<< " data:" << Values << endl;
				}

				OPstream toAbove(Pstream::scheduled, myComm.above());
				toAbove << Values;
			}
		}
	}


	template <class Container, class CombineOp>
	void PstreamTools::mapCombineGather(Container& Values, const CombineOp& cop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			mapCombineGather(Pstream::linearCommunication(), Values, cop);
		}
		else
		{
			mapCombineGather(Pstream::treeCommunication(), Values, cop);
		}
	}


	template <class Container>
	void PstreamTools::mapCombineScatter
	(
		const List<Pstream::commsStruct>& comms,
		Container& Values
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from up
			if (myComm.above() != -1)
			{
				IPstream fromAbove(Pstream::scheduled, myComm.above());
				fromAbove >> Values;

				if (Pstream::debug > 1)
				{
					Pout << " received from "
						<< myComm.above() << " data:" << Values << endl;
				}
			}

			// Send to my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];

				if (Pstream::debug > 1)
				{
					Pout << " sending to " << belowID << " data:" << Values << endl;
				}

				OPstream toBelow(Pstream::scheduled, belowID);
				toBelow << Values;
			}
		}
	}


	template <class Container>
	void PstreamTools::mapCombineScatter(Container& Values)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			mapCombineScatter(Pstream::linearCommunication(), Values);
		}
		else
		{
			mapCombineScatter(Pstream::treeCommunication(), Values);
		}
	}

	template <class T>
	void PstreamTools::gatherList
	(
		const List<Pstream::commsStruct>& comms,
		List<T>& Values
	)
	{
		if (Pstream::parRun())
		{
			if (Values.size() != Pstream::nProcs())
			{
				FatalErrorIn
				(
					"Pstream::gatherList(const List<Pstream::commsStruct>&"
					", List<T>)"
				) << "Size of list:" << Values.size()
					<< " does not equal the number of processors:"
					<< Pstream::nProcs()
					<< abort(FatalError);
			}

			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];
				const labelList& belowLeaves = comms[belowID].allBelow();

				if (contiguous<T>())
				{
					List<T> receivedValues(belowLeaves.size() + 1);

					IPstream::read
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<char*>(receivedValues.begin()),
						receivedValues.byteSize()
					);

					Values[belowID] = receivedValues[0];

					for (label leafI = 0; leafI < (belowLeaves).size(); leafI++)
					{
						Values[belowLeaves[leafI]] = receivedValues[leafI + 1];
					}
				}
				else
				{
					IPstream fromBelow(Pstream::scheduled, belowID);
					fromBelow >> Values[belowID];

					if (Pstream::debug > 1)
					{
						Pout << " received through "
							<< belowID << " data from:" << belowID
							<< " data:" << Values[belowID] << endl;
					}

					// Receive from all other processors below belowID
					for (label leafI = 0; leafI < (belowLeaves).size(); leafI++)
					{
						label leafID = belowLeaves[leafI];
						fromBelow >> Values[leafID];

						if (Pstream::debug > 1)
						{
							Pout << " received through "
								<< belowID << " data from:" << leafID
								<< " data:" << Values[leafID] << endl;
						}
					}
				}
			}

			// Send up from Values:
			// - my own value first
			// - all belowLeaves next
			if (myComm.above() != -1)
			{
				const labelList& belowLeaves = myComm.allBelow();

				if (Pstream::debug > 1)
				{
					Pout << " sending to " << myComm.above()
						<< " data from: " << Pstream::myProcNo()
						<< " data: " << Values[Pstream::myProcNo()] << endl;
				}

				if (contiguous<T>())
				{
					List<T> sendingValues(belowLeaves.size() + 1);
					sendingValues[0] = Values[Pstream::myProcNo()];

					for (label leafI = 0; leafI < (belowLeaves).size(); leafI++)
					{
						sendingValues[leafI + 1] = Values[belowLeaves[leafI]];
					}

					OPstream::write
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<const char*>(sendingValues.begin()),
						sendingValues.byteSize()
					);
				}
				else
				{
					OPstream toAbove(Pstream::scheduled, myComm.above());
					toAbove << Values[Pstream::myProcNo()];

					for (label leafI = 0; leafI < (belowLeaves).size(); leafI++)
					{
						label leafID = belowLeaves[leafI];

						if (Pstream::debug > 1)
						{
							Pout << " sending to "
								<< myComm.above() << " data from: " << leafID
								<< " data: " << Values[leafID] << endl;
						}
						toAbove << Values[leafID];
					}
				}
			}
		}
	}


	template <class T>
	void PstreamTools::gatherList(List<T>& Values)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			gatherList(Pstream::linearCommunication(), Values);
		}
		else
		{
			gatherList(Pstream::treeCommunication(), Values);
		}
	}


	template <class T>
	void PstreamTools::scatterList
	(
		const List<Pstream::commsStruct>& comms,
		List<T>& Values
	)
	{
		if (Pstream::parRun())
		{
			if (Values.size() != Pstream::nProcs())
			{
				FatalErrorIn
				(
					"Pstream::scatterList(const List<Pstream::commsStruct>&"
					", List<T>)"
				) << "Size of list:" << Values.size()
					<< " does not equal the number of processors:"
					<< Pstream::nProcs()
					<< abort(FatalError);
			}

			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from up
			if (myComm.above() != -1)
			{
				const labelList& notBelowLeaves = myComm.allNotBelow();

				if (contiguous<T>())
				{
					List<T> receivedValues(notBelowLeaves.size());

					IPstream::read
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<char*>(receivedValues.begin()),
						receivedValues.byteSize()
					);

					for (label leafI = 0; leafI < (notBelowLeaves).size(); leafI++)
					{
						Values[notBelowLeaves[leafI]] = receivedValues[leafI];
					}
				}
				else
				{
					IPstream fromAbove(Pstream::scheduled, myComm.above());

					for (label leafI = 0; leafI < (notBelowLeaves).size(); leafI++)
					{
						label leafID = notBelowLeaves[leafI];
						fromAbove >> Values[leafID];

						if (Pstream::debug)
						{
							Pout << " received through "
								<< myComm.above() << " data for:" << leafID
								<< " data:" << Values[leafID] << endl;
						}
					}
				}
			}

			// Send to my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				label belowID = myComm.below()[belowI];
				const labelList& notBelowLeaves = comms[belowID].allNotBelow();

				if (contiguous<T>())
				{
					List<T> sendingValues(notBelowLeaves.size());

					for (label leafI = 0; leafI < (notBelowLeaves).size(); leafI++)
					{
						sendingValues[leafI] = Values[notBelowLeaves[leafI]];
					}

					OPstream::write
					(
						Pstream::scheduled,
						belowID,
						reinterpret_cast<const char*>(sendingValues.begin()),
						sendingValues.byteSize()
					);
				}
				else
				{
					OPstream toBelow(Pstream::scheduled, belowID);

					// Send data destined for all other processors below belowID
					for (label leafI = 0; leafI < (notBelowLeaves).size(); leafI++)
					{
						label leafID = notBelowLeaves[leafI];
						toBelow << Values[leafID];

						if (Pstream::debug)
						{
							Pout << " sent through "
								<< belowID << " data for:" << leafID
								<< " data:" << Values[leafID] << endl;
						}
					}
				}
			}
		}
	}


	template <class T>
	void PstreamTools::scatterList(List<T>& Values)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			scatterList(Pstream::linearCommunication(), Values);
		}
		else
		{
			scatterList(Pstream::treeCommunication(), Values);
		}
	}

	template <class T, class BinaryOp>
	void PstreamTools::gather
	(
		const List<Pstream::commsStruct>& comms,
		T& Value,
		const BinaryOp& bop
	)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				T value;

				if (contiguous<T>())
				{
					IPstream::read
					(
						Pstream::scheduled,
						myComm.below()[belowI],
						reinterpret_cast<char*>(&value),
						sizeof(T)
					);
				}
				else
				{
					IPstream fromBelow(Pstream::scheduled, myComm.below()[belowI]);
					fromBelow >> value;
				}

				Value = bop(Value, value);
			}

			// Send up Value
			if (myComm.above() != -1)
			{
				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<const char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					OPstream toAbove(Pstream::scheduled, myComm.above());
					toAbove << Value;
				}
			}
		}
	}


	template <class T, class BinaryOp>
	void PstreamTools::gather(T& Value, const BinaryOp& bop)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			gather(Pstream::linearCommunication(), Value, bop);
		}
		else
		{
			gather(Pstream::treeCommunication(), Value, bop);
		}
	}


	template <class T>
	void PstreamTools::scatter(const List<Pstream::commsStruct>& comms, T& Value)
	{
		if (Pstream::parRun())
		{
			// Get my communication order
			const Pstream::commsStruct& myComm = comms[Pstream::myProcNo()];

			// Receive from up
			if (myComm.above() != -1)
			{
				if (contiguous<T>())
				{
					IPstream::read
					(
						Pstream::scheduled,
						myComm.above(),
						reinterpret_cast<char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					IPstream fromAbove(Pstream::scheduled, myComm.above());
					fromAbove >> Value;
				}
			}

			// Send to my downstairs neighbours
			for (label belowI = 0; belowI < (myComm.below()).size(); belowI++)
			{
				if (contiguous<T>())
				{
					OPstream::write
					(
						Pstream::scheduled,
						myComm.below()[belowI],
						reinterpret_cast<const char*>(&Value),
						sizeof(T)
					);
				}
				else
				{
					OPstream toBelow(Pstream::scheduled, myComm.below()[belowI]);
					toBelow << Value;
				}
			}
		}
	}


	template <class T>
	void PstreamTools::scatter(T& Value)
	{
		if (Pstream::nProcs() < Pstream::nProcsSimpleSum())
		{
			scatter(Pstream::linearCommunication(), Value);
		}
		else
		{
			scatter(Pstream::treeCommunication(), Value);
		}
	}
}