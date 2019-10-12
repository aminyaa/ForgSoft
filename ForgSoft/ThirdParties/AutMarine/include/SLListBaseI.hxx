#pragma once
#include <error.hxx>
#include <OSstream.hxx>

inline 
AutLib::SLListBase::link::link()
	: next_(0)
{}

inline 
AutLib::SLListBase::link::link(link* p)
	: next_(p)
{}

inline 
AutLib::SLListBase::SLListBase()
	: last_(0)
	, nElmts_(0)
{}


inline 
AutLib::SLListBase::SLListBase(link* a)
	: last_(a->next_ = a)
	, nElmts_(1)
{}

inline 
AutLib::SLListBase::~SLListBase()
{}

inline AutLib::label AutLib::SLListBase::size() const
{
	return nElmts_;
}


inline bool AutLib::SLListBase::empty() const
{
	return !nElmts_;
}


inline AutLib::SLListBase::link*
AutLib::SLListBase::first()
{
	if (!nElmts_)
	{
		FatalErrorIn("SLListBase::first()")
			<< "list is empty"
			<< abort(FatalError);
	}
	return last_->next_;
}


inline const AutLib::SLListBase::link*
AutLib::SLListBase::first() const
{
	if (!nElmts_)
	{
		FatalErrorIn("SLListBase::first() const")
			<< "list is empty"
			<< abort(FatalError);
	}
	return last_->next_;
}


inline AutLib::SLListBase::link*
AutLib::SLListBase::last()
{
	if (!nElmts_)
	{
		FatalErrorIn("SLListBase::last()")
			<< "list is empty"
			<< abort(FatalError);
	}
	return last_;
}


inline const AutLib::SLListBase::link*
AutLib::SLListBase::last() const
{
	if (!nElmts_)
	{
		FatalErrorIn("SLListBase::last() const")
			<< "list is empty"
			<< abort(FatalError);
	}
	return last_;
}


inline void AutLib::SLListBase::clear()
{
	last_ = 0;
	nElmts_ = 0;
}


inline void AutLib::SLListBase::transfer(SLListBase& lst)
{
	last_ = lst.last_;
	nElmts_ = lst.nElmts_;

	lst.clear();
}


inline AutLib::SLListBase::link* AutLib::SLListBase::remove
(
	SLListBase::iterator& it
)
{
	return remove(it.curElmt_);
}

inline AutLib::SLListBase::iterator::iterator(SLListBase& s, link* elmt)
	:
	curList_(s),
	curElmt_(elmt),
	curLink_(*curElmt_)
{
}


inline AutLib::SLListBase::iterator::iterator(SLListBase& s)
	:
	curList_(s),
	curElmt_(NULL),
	curLink_()
{
}


inline void AutLib::SLListBase::iterator::operator=(const iterator& iter)
{
	curElmt_ = iter.curElmt_;
	curLink_ = iter.curLink_;
}


inline bool AutLib::SLListBase::iterator::operator==(const iterator& iter) const
{
	return curElmt_ == iter.curElmt_;
}


inline bool AutLib::SLListBase::iterator::operator!=(const iterator& iter) const
{
	return curElmt_ != iter.curElmt_;
}


inline AutLib::SLListBase::link& AutLib::SLListBase::iterator::operator*()
{
	return *curElmt_;
}


inline AutLib::SLListBase::iterator& AutLib::SLListBase::iterator::operator++()
{
	if (curElmt_ == curList_.last_ || curList_.last_ == 0)
	{
		curElmt_ = 0;
	}
	else
	{
		curElmt_ = curLink_.next_;
		curLink_ = *curElmt_;
	}

	return *this;
}


inline AutLib::SLListBase::iterator
AutLib::SLListBase::iterator::operator++(int)
{
	iterator tmp = *this;
	++*this;
	return tmp;
}


inline AutLib::SLListBase::iterator
AutLib::SLListBase::begin()
{
	if (size())
	{
		return iterator(*this, first());
	}
	else
	{
		return endIter_;
	}
}


inline const AutLib::SLListBase::iterator&
AutLib::SLListBase::end()
{
	return endIter_;
}

inline AutLib::SLListBase::const_iterator::const_iterator
(
	const SLListBase& s,
	const link* elmt
)
	:
	curList_(s),
	curElmt_(elmt)
{
}


inline AutLib::SLListBase::const_iterator::const_iterator(const iterator& iter)
	:
	curList_(iter.curList_),
	curElmt_(iter.curElmt_)
{
}


inline void AutLib::SLListBase::const_iterator::operator=
(
	const const_iterator& iter
	)
{
	curElmt_ = iter.curElmt_;
}


inline bool AutLib::SLListBase::const_iterator::operator==
(
	const const_iterator& iter
	) const
{
	return curElmt_ == iter.curElmt_;
}


inline bool AutLib::SLListBase::const_iterator::operator!=
(
	const const_iterator& iter
	) const
{
	return curElmt_ != iter.curElmt_;
}


inline const AutLib::SLListBase::link&
AutLib::SLListBase::const_iterator::operator*()
{
	return *curElmt_;
}


inline AutLib::SLListBase::const_iterator&
AutLib::SLListBase::const_iterator::operator++()
{
	if (curElmt_ == curList_.last_)
	{
		curElmt_ = 0;
	}
	else
	{
		curElmt_ = curElmt_->next_;
	}

	return *this;
}


inline AutLib::SLListBase::const_iterator
AutLib::SLListBase::const_iterator::operator++(int)
{
	const_iterator tmp = *this;
	++*this;
	return tmp;
}


inline AutLib::SLListBase::const_iterator
AutLib::SLListBase::cbegin() const
{
	if (size())
	{
		return const_iterator(*this, first());
	}
	else
	{
		return endConstIter_;
	}
}


inline const AutLib::SLListBase::const_iterator&
AutLib::SLListBase::cend() const
{
	return endConstIter_;
}


inline AutLib::SLListBase::const_iterator
AutLib::SLListBase::begin() const
{
	return this->cbegin();
}


inline const AutLib::SLListBase::const_iterator&
AutLib::SLListBase::end() const
{
	return endConstIter_;
}