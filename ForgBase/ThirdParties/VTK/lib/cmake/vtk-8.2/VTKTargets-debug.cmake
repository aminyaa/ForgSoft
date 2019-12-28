#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vtksys" for configuration "Debug"
set_property(TARGET vtksys APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtksys PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtksys-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtksys-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtksys )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtksys "${_IMPORT_PREFIX}/lib/vtksys-8.2.lib" "${_IMPORT_PREFIX}/bin/vtksys-8.2.dll" )

# Import target "vtkCommonCore" for configuration "Debug"
set_property(TARGET vtkCommonCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonCore-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonCore "${_IMPORT_PREFIX}/lib/vtkCommonCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonCore-8.2.dll" )

# Import target "vtkCommonMath" for configuration "Debug"
set_property(TARGET vtkCommonMath APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonMath PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonMath-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonMath-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonMath "${_IMPORT_PREFIX}/lib/vtkCommonMath-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMath-8.2.dll" )

# Import target "vtkCommonMisc" for configuration "Debug"
set_property(TARGET vtkCommonMisc APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonMisc PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonMisc-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonMisc-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonMisc )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonMisc "${_IMPORT_PREFIX}/lib/vtkCommonMisc-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMisc-8.2.dll" )

# Import target "vtkCommonSystem" for configuration "Debug"
set_property(TARGET vtkCommonSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonSystem PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonSystem-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonSystem-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonSystem "${_IMPORT_PREFIX}/lib/vtkCommonSystem-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonSystem-8.2.dll" )

# Import target "vtkCommonTransforms" for configuration "Debug"
set_property(TARGET vtkCommonTransforms APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonTransforms PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonTransforms )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonTransforms "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-8.2.dll" )

# Import target "vtkCommonDataModel" for configuration "Debug"
set_property(TARGET vtkCommonDataModel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonDataModel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMisc;vtkCommonSystem;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonDataModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonDataModel "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-8.2.dll" )

# Import target "vtkCommonColor" for configuration "Debug"
set_property(TARGET vtkCommonColor APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonColor PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonColor-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonColor-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonColor "${_IMPORT_PREFIX}/lib/vtkCommonColor-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonColor-8.2.dll" )

# Import target "vtkCommonExecutionModel" for configuration "Debug"
set_property(TARGET vtkCommonExecutionModel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonExecutionModel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMisc;vtkCommonSystem"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonExecutionModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonExecutionModel "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-8.2.dll" )

# Import target "vtkCommonComputationalGeometry" for configuration "Debug"
set_property(TARGET vtkCommonComputationalGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkCommonComputationalGeometry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkCommonComputationalGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkCommonComputationalGeometry "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-8.2.dll" )

# Import target "vtkFiltersCore" for configuration "Debug"
set_property(TARGET vtkFiltersCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonSystem;vtkCommonTransforms"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersCore "${_IMPORT_PREFIX}/lib/vtkFiltersCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersCore-8.2.dll" )

# Import target "vtkFiltersGeneral" for configuration "Debug"
set_property(TARGET vtkFiltersGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersGeneral PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonComputationalGeometry;vtkCommonMath;vtkCommonSystem;vtkCommonTransforms"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersGeneral "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-8.2.dll" )

# Import target "vtkImagingCore" for configuration "Debug"
set_property(TARGET vtkImagingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonTransforms"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingCore "${_IMPORT_PREFIX}/lib/vtkImagingCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingCore-8.2.dll" )

# Import target "vtkImagingFourier" for configuration "Debug"
set_property(TARGET vtkImagingFourier APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingFourier PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingFourier-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingFourier-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingFourier )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingFourier "${_IMPORT_PREFIX}/lib/vtkImagingFourier-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingFourier-8.2.dll" )

# Import target "vtkFiltersStatistics" for configuration "Debug"
set_property(TARGET vtkFiltersStatistics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersStatistics PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMisc;vtkImagingFourier"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersStatistics )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersStatistics "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-8.2.dll" )

# Import target "vtkFiltersExtraction" for configuration "Debug"
set_property(TARGET vtkFiltersExtraction APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersExtraction PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkFiltersCore;vtkFiltersStatistics"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersExtraction )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersExtraction "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-8.2.dll" )

# Import target "vtkInfovisCore" for configuration "Debug"
set_property(TARGET vtkInfovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkInfovisCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkInfovisCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkFiltersExtraction;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkInfovisCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkInfovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkInfovisCore "${_IMPORT_PREFIX}/lib/vtkInfovisCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisCore-8.2.dll" )

# Import target "vtkFiltersGeometry" for configuration "Debug"
set_property(TARGET vtkFiltersGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersGeometry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkFiltersCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersGeometry "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-8.2.dll" )

# Import target "vtkFiltersSources" for configuration "Debug"
set_property(TARGET vtkFiltersSources APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersSources PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersSources-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonComputationalGeometry;vtkCommonCore;vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersSources-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersSources "${_IMPORT_PREFIX}/lib/vtkFiltersSources-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSources-8.2.dll" )

# Import target "vtkRenderingCore" for configuration "Debug"
set_property(TARGET vtkRenderingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonColor;vtkCommonComputationalGeometry;vtkCommonSystem;vtkCommonTransforms;vtkFiltersGeneral;vtkFiltersGeometry;vtkFiltersSources;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingCore "${_IMPORT_PREFIX}/lib/vtkRenderingCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingCore-8.2.dll" )

# Import target "vtkzlib" for configuration "Debug"
set_property(TARGET vtkzlib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkzlib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkzlib-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkzlib-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkzlib )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkzlib "${_IMPORT_PREFIX}/lib/vtkzlib-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkzlib-8.2.dll" )

# Import target "vtkfreetype" for configuration "Debug"
set_property(TARGET vtkfreetype APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkfreetype PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkfreetype-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkfreetype-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkfreetype )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkfreetype "${_IMPORT_PREFIX}/lib/vtkfreetype-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkfreetype-8.2.dll" )

# Import target "vtkRenderingFreeType" for configuration "Debug"
set_property(TARGET vtkRenderingFreeType APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingFreeType PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingFreeType )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingFreeType "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-8.2.dll" )

# Import target "vtkRenderingContext2D" for configuration "Debug"
set_property(TARGET vtkRenderingContext2D APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingContext2D PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonTransforms;vtkFiltersGeneral;vtkRenderingFreeType"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingContext2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingContext2D "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-8.2.dll" )

# Import target "vtkChartsCore" for configuration "Debug"
set_property(TARGET vtkChartsCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkChartsCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkChartsCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonColor;vtkCommonExecutionModel;vtkCommonTransforms;vtkInfovisCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkChartsCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkChartsCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkChartsCore "${_IMPORT_PREFIX}/lib/vtkChartsCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkChartsCore-8.2.dll" )

# Import target "vtkdoubleconversion" for configuration "Debug"
set_property(TARGET vtkdoubleconversion APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkdoubleconversion PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkdoubleconversion )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkdoubleconversion "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-8.2.dll" )

# Import target "vtklz4" for configuration "Debug"
set_property(TARGET vtklz4 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtklz4 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtklz4-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtklz4-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtklz4 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtklz4 "${_IMPORT_PREFIX}/lib/vtklz4-8.2.lib" "${_IMPORT_PREFIX}/bin/vtklz4-8.2.dll" )

# Import target "vtklzma" for configuration "Debug"
set_property(TARGET vtklzma APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtklzma PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtklzma-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtklzma-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtklzma )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtklzma "${_IMPORT_PREFIX}/lib/vtklzma-8.2.lib" "${_IMPORT_PREFIX}/bin/vtklzma-8.2.dll" )

# Import target "vtkIOCore" for configuration "Debug"
set_property(TARGET vtkIOCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMisc;vtklz4;vtklzma;vtksys;vtkzlib;vtkdoubleconversion"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOCore "${_IMPORT_PREFIX}/lib/vtkIOCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOCore-8.2.dll" )

# Import target "vtkIOLegacy" for configuration "Debug"
set_property(TARGET vtkIOLegacy APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOLegacy PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOLegacy-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMisc;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOLegacy-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOLegacy )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOLegacy "${_IMPORT_PREFIX}/lib/vtkIOLegacy-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOLegacy-8.2.dll" )

# Import target "vtkexpat" for configuration "Debug"
set_property(TARGET vtkexpat APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkexpat PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkexpat-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkexpat-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkexpat )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkexpat "${_IMPORT_PREFIX}/lib/vtkexpat-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkexpat-8.2.dll" )

# Import target "vtkIOXMLParser" for configuration "Debug"
set_property(TARGET vtkIOXMLParser APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOXMLParser PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkIOCore;vtkexpat;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOXMLParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOXMLParser "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-8.2.dll" )

# Import target "vtkIOXML" for configuration "Debug"
set_property(TARGET vtkIOXML APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOXML PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOXML-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMisc;vtkCommonSystem;vtkIOCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOXML-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOXML )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOXML "${_IMPORT_PREFIX}/lib/vtkIOXML-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOXML-8.2.dll" )

# Import target "vtklibxml2" for configuration "Debug"
set_property(TARGET vtklibxml2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtklibxml2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtklibxml2-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtklibxml2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtklibxml2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtklibxml2 "${_IMPORT_PREFIX}/lib/vtklibxml2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtklibxml2-8.2.dll" )

# Import target "vtkIOInfovis" for configuration "Debug"
set_property(TARGET vtkIOInfovis APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOInfovis PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOInfovis-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMisc;vtkIOCore;vtkIOXMLParser;vtkInfovisCore;vtklibxml2;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOInfovis-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOInfovis )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOInfovis "${_IMPORT_PREFIX}/lib/vtkIOInfovis-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOInfovis-8.2.dll" )

# Import target "vtkglew" for configuration "Debug"
set_property(TARGET vtkglew APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkglew PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkglew-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkglew-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkglew )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkglew "${_IMPORT_PREFIX}/lib/vtkglew-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkglew-8.2.dll" )

# Import target "vtkRenderingOpenGL2" for configuration "Debug"
set_property(TARGET vtkRenderingOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonExecutionModel;vtkCommonMath;vtkCommonSystem;vtkCommonTransforms;vtkglew;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-8.2.dll" )

# Import target "vtkRenderingContextOpenGL2" for configuration "Debug"
set_property(TARGET vtkRenderingContextOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingContextOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingContextOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonTransforms;vtkImagingCore;vtkglew"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingContextOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingContextOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingContextOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingContextOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingContextOpenGL2-8.2.dll" )

# Import target "vtkDICOMParser" for configuration "Debug"
set_property(TARGET vtkDICOMParser APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkDICOMParser PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkDICOMParser-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkDICOMParser-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkDICOMParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkDICOMParser "${_IMPORT_PREFIX}/lib/vtkDICOMParser-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkDICOMParser-8.2.dll" )

# Import target "vtkmetaio" for configuration "Debug"
set_property(TARGET vtkmetaio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkmetaio PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkmetaio-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkmetaio-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkmetaio )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkmetaio "${_IMPORT_PREFIX}/lib/vtkmetaio-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkmetaio-8.2.dll" )

# Import target "vtkjpeg" for configuration "Debug"
set_property(TARGET vtkjpeg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkjpeg PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkjpeg-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkjpeg-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkjpeg )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkjpeg "${_IMPORT_PREFIX}/lib/vtkjpeg-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkjpeg-8.2.dll" )

# Import target "vtkpng" for configuration "Debug"
set_property(TARGET vtkpng APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkpng PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkpng-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkpng-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkpng )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkpng "${_IMPORT_PREFIX}/lib/vtkpng-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkpng-8.2.dll" )

# Import target "vtktiff" for configuration "Debug"
set_property(TARGET vtktiff APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtktiff PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtktiff-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtktiff-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtktiff )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtktiff "${_IMPORT_PREFIX}/lib/vtktiff-8.2.lib" "${_IMPORT_PREFIX}/bin/vtktiff-8.2.dll" )

# Import target "vtkIOImage" for configuration "Debug"
set_property(TARGET vtkIOImage APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOImage PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOImage-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMath;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkDICOMParser;vtkmetaio;vtkjpeg;vtkpng;vtksys;vtktiff;vtkzlib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOImage-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOImage "${_IMPORT_PREFIX}/lib/vtkIOImage-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOImage-8.2.dll" )

# Import target "vtkTestingRendering" for configuration "Debug"
set_property(TARGET vtkTestingRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkTestingRendering PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkTestingRendering-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonSystem;vtkIOImage;vtkImagingCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkTestingRendering-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkTestingRendering )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkTestingRendering "${_IMPORT_PREFIX}/lib/vtkTestingRendering-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkTestingRendering-8.2.dll" )

# Import target "vtkImagingSources" for configuration "Debug"
set_property(TARGET vtkImagingSources APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingSources PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingSources-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkImagingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingSources-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingSources "${_IMPORT_PREFIX}/lib/vtkImagingSources-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingSources-8.2.dll" )

# Import target "vtkFiltersHybrid" for configuration "Debug"
set_property(TARGET vtkFiltersHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersHybrid PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonMisc;vtkFiltersCore;vtkFiltersGeneral;vtkFiltersGeometry;vtkImagingCore;vtkImagingSources;vtkRenderingCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersHybrid "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-8.2.dll" )

# Import target "vtkFiltersModeling" for configuration "Debug"
set_property(TARGET vtkFiltersModeling APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersModeling PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonTransforms;vtkFiltersCore;vtkFiltersSources"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersModeling )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersModeling "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-8.2.dll" )

# Import target "vtkImagingColor" for configuration "Debug"
set_property(TARGET vtkImagingColor APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingColor PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingColor-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonSystem"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingColor-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingColor "${_IMPORT_PREFIX}/lib/vtkImagingColor-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingColor-8.2.dll" )

# Import target "vtkImagingGeneral" for configuration "Debug"
set_property(TARGET vtkImagingGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingGeneral PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkImagingSources"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingGeneral "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-8.2.dll" )

# Import target "vtkImagingHybrid" for configuration "Debug"
set_property(TARGET vtkImagingHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingHybrid PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkIOImage;vtkImagingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingHybrid "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-8.2.dll" )

# Import target "vtkInteractionStyle" for configuration "Debug"
set_property(TARGET vtkInteractionStyle APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkInteractionStyle PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonMath;vtkCommonTransforms;vtkFiltersExtraction;vtkFiltersSources"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkInteractionStyle )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkInteractionStyle "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-8.2.dll" )

# Import target "vtkRenderingAnnotation" for configuration "Debug"
set_property(TARGET vtkRenderingAnnotation APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingAnnotation PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral;vtkFiltersSources;vtkImagingColor;vtkRenderingFreeType"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingAnnotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingAnnotation "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-8.2.dll" )

# Import target "vtkRenderingVolume" for configuration "Debug"
set_property(TARGET vtkRenderingVolume APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingVolume PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMath;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkIOXML;vtkImagingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingVolume )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingVolume "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-8.2.dll" )

# Import target "vtkInteractionWidgets" for configuration "Debug"
set_property(TARGET vtkInteractionWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkInteractionWidgets PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonComputationalGeometry;vtkCommonDataModel;vtkCommonMath;vtkCommonSystem;vtkCommonTransforms;vtkFiltersCore;vtkFiltersHybrid;vtkFiltersModeling;vtkImagingColor;vtkImagingCore;vtkImagingGeneral;vtkImagingHybrid;vtkInteractionStyle;vtkRenderingAnnotation;vtkRenderingFreeType;vtkRenderingVolume"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkInteractionWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkInteractionWidgets "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-8.2.dll" )

# Import target "vtkViewsCore" for configuration "Debug"
set_property(TARGET vtkViewsCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkViewsCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkViewsCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkFiltersGeneral;vtkRenderingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkViewsCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkViewsCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkViewsCore "${_IMPORT_PREFIX}/lib/vtkViewsCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkViewsCore-8.2.dll" )

# Import target "vtkViewsContext2D" for configuration "Debug"
set_property(TARGET vtkViewsContext2D APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkViewsContext2D PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkViewsContext2D-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkRenderingContext2D"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkViewsContext2D-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkViewsContext2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkViewsContext2D "${_IMPORT_PREFIX}/lib/vtkViewsContext2D-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkViewsContext2D-8.2.dll" )

# Import target "vtkFiltersProgrammable" for configuration "Debug"
set_property(TARGET vtkFiltersProgrammable APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersProgrammable PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersProgrammable-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonTransforms"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersProgrammable-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersProgrammable )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersProgrammable "${_IMPORT_PREFIX}/lib/vtkFiltersProgrammable-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersProgrammable-8.2.dll" )

# Import target "verdict" for configuration "Debug"
set_property(TARGET verdict APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(verdict PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkverdict-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkverdict-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS verdict )
list(APPEND _IMPORT_CHECK_FILES_FOR_verdict "${_IMPORT_PREFIX}/lib/vtkverdict-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkverdict-8.2.dll" )

# Import target "vtkFiltersVerdict" for configuration "Debug"
set_property(TARGET vtkFiltersVerdict APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersVerdict PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersVerdict-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersVerdict-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersVerdict )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersVerdict "${_IMPORT_PREFIX}/lib/vtkFiltersVerdict-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersVerdict-8.2.dll" )

# Import target "vtkFiltersGeneric" for configuration "Debug"
set_property(TARGET vtkFiltersGeneric APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersGeneric PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersGeneric-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkFiltersCore;vtkFiltersSources"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersGeneric-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersGeneric )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersGeneric "${_IMPORT_PREFIX}/lib/vtkFiltersGeneric-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeneric-8.2.dll" )

# Import target "vtkIOGeometry" for configuration "Debug"
set_property(TARGET vtkIOGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOGeometry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOGeometry-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkIOImage;vtksys;vtkzlib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOGeometry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOGeometry "${_IMPORT_PREFIX}/lib/vtkIOGeometry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOGeometry-8.2.dll" )

# Import target "vtkTestingGenericBridge" for configuration "Debug"
set_property(TARGET vtkTestingGenericBridge APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkTestingGenericBridge PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkTestingGenericBridge-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMisc"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkTestingGenericBridge-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkTestingGenericBridge )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkTestingGenericBridge "${_IMPORT_PREFIX}/lib/vtkTestingGenericBridge-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkTestingGenericBridge-8.2.dll" )

# Import target "vtkDomainsChemistry" for configuration "Debug"
set_property(TARGET vtkDomainsChemistry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkDomainsChemistry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral;vtkFiltersSources;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkDomainsChemistry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkDomainsChemistry "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-8.2.dll" )

# Import target "vtkDomainsChemistryOpenGL2" for configuration "Debug"
set_property(TARGET vtkDomainsChemistryOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkDomainsChemistryOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkDomainsChemistryOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkRenderingCore;vtkglew"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkDomainsChemistryOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkDomainsChemistryOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkDomainsChemistryOpenGL2 "${_IMPORT_PREFIX}/lib/vtkDomainsChemistryOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsChemistryOpenGL2-8.2.dll" )

# Import target "vtkParallelCore" for configuration "Debug"
set_property(TARGET vtkParallelCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkParallelCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkParallelCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonSystem;vtkIOLegacy;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkParallelCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkParallelCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkParallelCore "${_IMPORT_PREFIX}/lib/vtkParallelCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkParallelCore-8.2.dll" )

# Import target "vtkFiltersParallel" for configuration "Debug"
set_property(TARGET vtkFiltersParallel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersParallel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersParallel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonSystem;vtkCommonTransforms;vtkIOLegacy;vtkParallelCore;vtkRenderingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersParallel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersParallel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersParallel "${_IMPORT_PREFIX}/lib/vtkFiltersParallel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallel-8.2.dll" )

# Import target "vtkParallelMPI" for configuration "Debug"
set_property(TARGET vtkParallelMPI APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkParallelMPI PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkParallelMPI-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkParallelMPI-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkParallelMPI )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkParallelMPI "${_IMPORT_PREFIX}/lib/vtkParallelMPI-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkParallelMPI-8.2.dll" )

# Import target "vtkFiltersParallelMPI" for configuration "Debug"
set_property(TARGET vtkFiltersParallelMPI APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersParallelMPI PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersParallelMPI-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkFiltersGeneral;vtkFiltersParallel;vtkIOLegacy;vtkParallelCore;vtkParallelMPI"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersParallelMPI-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersParallelMPI )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersParallelMPI "${_IMPORT_PREFIX}/lib/vtkFiltersParallelMPI-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallelMPI-8.2.dll" )

# Import target "vtkDomainsParallelChemistry" for configuration "Debug"
set_property(TARGET vtkDomainsParallelChemistry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkDomainsParallelChemistry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkDomainsParallelChemistry-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkParallelMPI;vtkFiltersParallelMPI"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkDomainsParallelChemistry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkDomainsParallelChemistry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkDomainsParallelChemistry "${_IMPORT_PREFIX}/lib/vtkDomainsParallelChemistry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsParallelChemistry-8.2.dll" )

# Import target "vtkFiltersAMR" for configuration "Debug"
set_property(TARGET vtkFiltersAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersAMR PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonMath;vtkCommonSystem;vtkFiltersCore;vtkIOXML;vtkParallelCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersAMR "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-8.2.dll" )

# Import target "vtkhdf5_src" for configuration "Debug"
set_property(TARGET vtkhdf5_src APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkhdf5_src PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkhdf5-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkhdf5-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkhdf5_src )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkhdf5_src "${_IMPORT_PREFIX}/lib/vtkhdf5-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkhdf5-8.2.dll" )

# Import target "vtkhdf5_hl_src" for configuration "Debug"
set_property(TARGET vtkhdf5_hl_src APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkhdf5_hl_src PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkhdf5_hl-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkhdf5_hl-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkhdf5_hl_src )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkhdf5_hl_src "${_IMPORT_PREFIX}/lib/vtkhdf5_hl-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkhdf5_hl-8.2.dll" )

# Import target "vtkIOAMR" for configuration "Debug"
set_property(TARGET vtkIOAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOAMR PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOAMR-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonSystem;vtkFiltersAMR;vtkParallelCore;vtkhdf5_src;vtkhdf5_hl_src;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOAMR-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOAMR "${_IMPORT_PREFIX}/lib/vtkIOAMR-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOAMR-8.2.dll" )

# Import target "vtknetcdf" for configuration "Debug"
set_property(TARGET vtknetcdf APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtknetcdf PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkNetCDF-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkNetCDF-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtknetcdf )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtknetcdf "${_IMPORT_PREFIX}/lib/vtkNetCDF-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkNetCDF-8.2.dll" )

# Import target "vtkexodusII" for configuration "Debug"
set_property(TARGET vtkexodusII APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkexodusII PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkexodusII-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkexodusII-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkexodusII )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkexodusII "${_IMPORT_PREFIX}/lib/vtkexodusII-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkexodusII-8.2.dll" )

# Import target "vtkIOExodus" for configuration "Debug"
set_property(TARGET vtkIOExodus APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOExodus PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOExodus-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkFiltersCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOExodus-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOExodus )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOExodus "${_IMPORT_PREFIX}/lib/vtkIOExodus-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOExodus-8.2.dll" )

# Import target "vtkImagingMath" for configuration "Debug"
set_property(TARGET vtkImagingMath APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingMath PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingMath-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingMath-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingMath "${_IMPORT_PREFIX}/lib/vtkImagingMath-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingMath-8.2.dll" )

# Import target "vtkRenderingVolumeOpenGL2" for configuration "Debug"
set_property(TARGET vtkRenderingVolumeOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingVolumeOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonSystem;vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral;vtkFiltersSources;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingVolumeOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingVolumeOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-8.2.dll" )

# Import target "vtkFiltersFlowPaths" for configuration "Debug"
set_property(TARGET vtkFiltersFlowPaths APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersFlowPaths PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkFiltersCore;vtkFiltersGeometry;vtkFiltersSources;vtkIOCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersFlowPaths )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersFlowPaths "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-8.2.dll" )

# Import target "vtkFiltersImaging" for configuration "Debug"
set_property(TARGET vtkFiltersImaging APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersImaging PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersImaging-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonSystem;vtkImagingGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersImaging-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersImaging )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersImaging "${_IMPORT_PREFIX}/lib/vtkFiltersImaging-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersImaging-8.2.dll" )

# Import target "vtkRenderingLabel" for configuration "Debug"
set_property(TARGET vtkRenderingLabel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingLabel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingLabel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonSystem;vtkCommonTransforms;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingLabel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingLabel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingLabel "${_IMPORT_PREFIX}/lib/vtkRenderingLabel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingLabel-8.2.dll" )

# Import target "vtkFiltersHyperTree" for configuration "Debug"
set_property(TARGET vtkFiltersHyperTree APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersHyperTree PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersHyperTree-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonSystem;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersHyperTree-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersHyperTree )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersHyperTree "${_IMPORT_PREFIX}/lib/vtkFiltersHyperTree-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersHyperTree-8.2.dll" )

# Import target "vtkImagingStencil" for configuration "Debug"
set_property(TARGET vtkImagingStencil APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingStencil PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingStencil-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonComputationalGeometry;vtkCommonCore;vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingStencil-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingStencil )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingStencil "${_IMPORT_PREFIX}/lib/vtkImagingStencil-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingStencil-8.2.dll" )

# Import target "vtkFiltersParallelGeometry" for configuration "Debug"
set_property(TARGET vtkFiltersParallelGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersParallelGeometry PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersParallelGeometry-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkFiltersExtraction;vtkFiltersGeneral;vtkIOLegacy;vtkParallelCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersParallelGeometry-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersParallelGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersParallelGeometry "${_IMPORT_PREFIX}/lib/vtkFiltersParallelGeometry-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallelGeometry-8.2.dll" )

# Import target "vtkIONetCDF" for configuration "Debug"
set_property(TARGET vtkIONetCDF APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIONetCDF PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIONetCDF-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtknetcdf;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIONetCDF-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIONetCDF )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIONetCDF "${_IMPORT_PREFIX}/lib/vtkIONetCDF-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIONetCDF-8.2.dll" )

# Import target "vtkjsoncpp" for configuration "Debug"
set_property(TARGET vtkjsoncpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkjsoncpp PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkjsoncpp-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkjsoncpp-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkjsoncpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkjsoncpp "${_IMPORT_PREFIX}/lib/vtkjsoncpp-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkjsoncpp-8.2.dll" )

# Import target "vtkIOParallel" for configuration "Debug"
set_property(TARGET vtkIOParallel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOParallel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOParallel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMisc;vtkCommonSystem;vtkFiltersCore;vtkFiltersExtraction;vtkFiltersParallel;vtkParallelCore;vtkexodusII;vtkjsoncpp;vtknetcdf;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOParallel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOParallel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOParallel "${_IMPORT_PREFIX}/lib/vtkIOParallel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOParallel-8.2.dll" )

# Import target "vtkIOParallelXML" for configuration "Debug"
set_property(TARGET vtkIOParallelXML APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOParallelXML PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOParallelXML-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMisc;vtkParallelCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOParallelXML-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOParallelXML )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOParallelXML "${_IMPORT_PREFIX}/lib/vtkIOParallelXML-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOParallelXML-8.2.dll" )

# Import target "vtkFiltersParallelImaging" for configuration "Debug"
set_property(TARGET vtkFiltersParallelImaging APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersParallelImaging PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersParallelImaging-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonSystem;vtkFiltersExtraction;vtkFiltersStatistics;vtkImagingGeneral;vtkParallelCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersParallelImaging-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersParallelImaging )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersParallelImaging "${_IMPORT_PREFIX}/lib/vtkFiltersParallelImaging-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallelImaging-8.2.dll" )

# Import target "vtkFiltersParallelVerdict" for configuration "Debug"
set_property(TARGET vtkFiltersParallelVerdict APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersParallelVerdict PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersParallelVerdict-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersParallelVerdict-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersParallelVerdict )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersParallelVerdict "${_IMPORT_PREFIX}/lib/vtkFiltersParallelVerdict-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallelVerdict-8.2.dll" )

# Import target "vtkFiltersPoints" for configuration "Debug"
set_property(TARGET vtkFiltersPoints APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersPoints PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersPoints-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersPoints-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersPoints )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersPoints "${_IMPORT_PREFIX}/lib/vtkFiltersPoints-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersPoints-8.2.dll" )

# Import target "vtkFiltersSMP" for configuration "Debug"
set_property(TARGET vtkFiltersSMP APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersSMP PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersSMP-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonMath;vtkCommonSystem"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersSMP-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersSMP )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersSMP "${_IMPORT_PREFIX}/lib/vtkFiltersSMP-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSMP-8.2.dll" )

# Import target "vtkFiltersSelection" for configuration "Debug"
set_property(TARGET vtkFiltersSelection APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersSelection PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersSelection-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersSelection-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersSelection )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersSelection "${_IMPORT_PREFIX}/lib/vtkFiltersSelection-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSelection-8.2.dll" )

# Import target "vtkFiltersTexture" for configuration "Debug"
set_property(TARGET vtkFiltersTexture APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersTexture PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonTransforms;vtkFiltersGeneral"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersTexture )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersTexture "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-8.2.dll" )

# Import target "vtkFiltersTopology" for configuration "Debug"
set_property(TARGET vtkFiltersTopology APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkFiltersTopology PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkFiltersTopology-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkFiltersTopology-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkFiltersTopology )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkFiltersTopology "${_IMPORT_PREFIX}/lib/vtkFiltersTopology-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersTopology-8.2.dll" )

# Import target "vtkGUISupportQt" for configuration "Debug"
set_property(TARGET vtkGUISupportQt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkGUISupportQt PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkFiltersExtraction;vtkInteractionStyle"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkGUISupportQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkGUISupportQt "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-8.2.dll" )

# Import target "vtksqlite" for configuration "Debug"
set_property(TARGET vtksqlite APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtksqlite PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtksqlite-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtksqlite-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtksqlite )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtksqlite "${_IMPORT_PREFIX}/lib/vtksqlite-8.2.lib" "${_IMPORT_PREFIX}/bin/vtksqlite-8.2.dll" )

# Import target "vtkIOSQL" for configuration "Debug"
set_property(TARGET vtkIOSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOSQL PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOSQL-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtksqlite;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOSQL-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOSQL )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOSQL "${_IMPORT_PREFIX}/lib/vtkIOSQL-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOSQL-8.2.dll" )

# Import target "vtkGUISupportQtSQL" for configuration "Debug"
set_property(TARGET vtkGUISupportQtSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkGUISupportQtSQL PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkGUISupportQtSQL-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkGUISupportQtSQL-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkGUISupportQtSQL )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkGUISupportQtSQL "${_IMPORT_PREFIX}/lib/vtkGUISupportQtSQL-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkGUISupportQtSQL-8.2.dll" )

# Import target "vtkInfovisLayout" for configuration "Debug"
set_property(TARGET vtkInfovisLayout APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkInfovisLayout PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonComputationalGeometry;vtkCommonSystem;vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral;vtkFiltersModeling;vtkFiltersSources;vtkImagingHybrid;vtkInfovisCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkInfovisLayout )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkInfovisLayout "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-8.2.dll" )

# Import target "vtklibproj" for configuration "Debug"
set_property(TARGET vtklibproj APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtklibproj PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkproj-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkproj-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtklibproj )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtklibproj "${_IMPORT_PREFIX}/lib/vtkproj-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkproj-8.2.dll" )

# Import target "vtkGeovisCore" for configuration "Debug"
set_property(TARGET vtkGeovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkGeovisCore PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkGeovisCore-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonSystem;vtkFiltersCore;vtkFiltersGeneral;vtkIOImage;vtkIOXML;vtkImagingCore;vtkImagingSources;vtkInfovisLayout"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkGeovisCore-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkGeovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkGeovisCore "${_IMPORT_PREFIX}/lib/vtkGeovisCore-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkGeovisCore-8.2.dll" )

# Import target "vtkViewsInfovis" for configuration "Debug"
set_property(TARGET vtkViewsInfovis APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkViewsInfovis PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkViewsInfovis-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkChartsCore;vtkCommonColor;vtkCommonTransforms;vtkFiltersCore;vtkFiltersExtraction;vtkFiltersGeneral;vtkFiltersGeometry;vtkFiltersImaging;vtkFiltersModeling;vtkFiltersSources;vtkFiltersStatistics;vtkImagingGeneral;vtkInfovisCore;vtkInfovisLayout;vtkInteractionWidgets;vtkRenderingAnnotation;vtkRenderingCore;vtkRenderingLabel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkViewsInfovis-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkViewsInfovis )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkViewsInfovis "${_IMPORT_PREFIX}/lib/vtkViewsInfovis-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkViewsInfovis-8.2.dll" )

# Import target "vtkViewsGeovis" for configuration "Debug"
set_property(TARGET vtkViewsGeovis APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkViewsGeovis PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkViewsGeovis-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkGeovisCore;vtkInfovisLayout;vtkInteractionStyle;vtkRenderingCore;vtkViewsCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkViewsGeovis-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkViewsGeovis )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkViewsGeovis "${_IMPORT_PREFIX}/lib/vtkViewsGeovis-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkViewsGeovis-8.2.dll" )

# Import target "vtkIOAsynchronous" for configuration "Debug"
set_property(TARGET vtkIOAsynchronous APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOAsynchronous PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOAsynchronous-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMath;vtkCommonMisc;vtkCommonSystem;vtkjpeg;vtkpng;vtksys;vtktiff;vtkzlib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOAsynchronous-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOAsynchronous )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOAsynchronous "${_IMPORT_PREFIX}/lib/vtkIOAsynchronous-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOAsynchronous-8.2.dll" )

# Import target "vtkpugixml" for configuration "Debug"
set_property(TARGET vtkpugixml APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkpugixml PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkpugixml-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkpugixml-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkpugixml )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkpugixml "${_IMPORT_PREFIX}/lib/vtkpugixml-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkpugixml-8.2.dll" )

# Import target "vtkIOCityGML" for configuration "Debug"
set_property(TARGET vtkIOCityGML APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOCityGML PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOCityGML-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOCityGML-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOCityGML )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOCityGML "${_IMPORT_PREFIX}/lib/vtkIOCityGML-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOCityGML-8.2.dll" )

# Import target "vtkIOEnSight" for configuration "Debug"
set_property(TARGET vtkIOEnSight APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOEnSight PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOEnSight-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOEnSight-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOEnSight )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOEnSight "${_IMPORT_PREFIX}/lib/vtkIOEnSight-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOEnSight-8.2.dll" )

# Import target "vtkgl2ps" for configuration "Debug"
set_property(TARGET vtkgl2ps APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkgl2ps PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkgl2ps-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkgl2ps-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkgl2ps )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkgl2ps "${_IMPORT_PREFIX}/lib/vtkgl2ps-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkgl2ps-8.2.dll" )

# Import target "vtkRenderingGL2PSOpenGL2" for configuration "Debug"
set_property(TARGET vtkRenderingGL2PSOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingGL2PSOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingGL2PSOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonMath;vtkRenderingCore;vtkgl2ps"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingGL2PSOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingGL2PSOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingGL2PSOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingGL2PSOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingGL2PSOpenGL2-8.2.dll" )

# Import target "vtkIOExport" for configuration "Debug"
set_property(TARGET vtkIOExport APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOExport PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOExport-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMath;vtkCommonTransforms;vtkFiltersGeometry;vtkImagingCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOExport-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOExport )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOExport "${_IMPORT_PREFIX}/lib/vtkIOExport-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOExport-8.2.dll" )

# Import target "vtkIOExportOpenGL2" for configuration "Debug"
set_property(TARGET vtkIOExportOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOExportOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOExportOpenGL2-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkImagingCore;vtkRenderingCore;vtkgl2ps"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOExportOpenGL2-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOExportOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOExportOpenGL2 "${_IMPORT_PREFIX}/lib/vtkIOExportOpenGL2-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOExportOpenGL2-8.2.dll" )

# Import target "vtkInteractionImage" for configuration "Debug"
set_property(TARGET vtkInteractionImage APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkInteractionImage PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkInteractionImage-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonExecutionModel;vtkImagingColor;vtkImagingCore;vtkInteractionStyle;vtkInteractionWidgets"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkInteractionImage-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkInteractionImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkInteractionImage "${_IMPORT_PREFIX}/lib/vtkInteractionImage-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionImage-8.2.dll" )

# Import target "vtklibharu" for configuration "Debug"
set_property(TARGET vtklibharu APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtklibharu PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtklibharu-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtklibharu-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtklibharu )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtklibharu "${_IMPORT_PREFIX}/lib/vtklibharu-8.2.lib" "${_IMPORT_PREFIX}/bin/vtklibharu-8.2.dll" )

# Import target "vtkIOExportPDF" for configuration "Debug"
set_property(TARGET vtkIOExportPDF APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOExportPDF PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOExportPDF-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkImagingCore;vtklibharu"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOExportPDF-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOExportPDF )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOExportPDF "${_IMPORT_PREFIX}/lib/vtkIOExportPDF-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOExportPDF-8.2.dll" )

# Import target "vtkIOImport" for configuration "Debug"
set_property(TARGET vtkIOImport APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOImport PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOImport-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonTransforms;vtkFiltersCore;vtkFiltersSources;vtkIOImage"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOImport-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOImport )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOImport "${_IMPORT_PREFIX}/lib/vtkIOImport-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOImport-8.2.dll" )

# Import target "vtkIOLSDyna" for configuration "Debug"
set_property(TARGET vtkIOLSDyna APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOLSDyna PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOLSDyna-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOLSDyna-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOLSDyna )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOLSDyna "${_IMPORT_PREFIX}/lib/vtkIOLSDyna-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOLSDyna-8.2.dll" )

# Import target "vtkIOMINC" for configuration "Debug"
set_property(TARGET vtkIOMINC APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOMINC PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOMINC-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMath;vtkCommonMisc;vtkCommonTransforms;vtkFiltersHybrid;vtkRenderingCore;vtknetcdf;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOMINC-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOMINC )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOMINC "${_IMPORT_PREFIX}/lib/vtkIOMINC-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOMINC-8.2.dll" )

# Import target "vtkIOMPIImage" for configuration "Debug"
set_property(TARGET vtkIOMPIImage APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOMPIImage PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOMPIImage-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonTransforms;vtkParallelCore;vtkParallelMPI;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOMPIImage-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOMPIImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOMPIImage "${_IMPORT_PREFIX}/lib/vtkIOMPIImage-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOMPIImage-8.2.dll" )

# Import target "vtkIOMPIParallel" for configuration "Debug"
set_property(TARGET vtkIOMPIParallel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOMPIParallel PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOMPIParallel-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMisc;vtkParallelMPI;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOMPIParallel-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOMPIParallel )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOMPIParallel "${_IMPORT_PREFIX}/lib/vtkIOMPIParallel-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOMPIParallel-8.2.dll" )

# Import target "vtkogg" for configuration "Debug"
set_property(TARGET vtkogg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkogg PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkogg-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkogg-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkogg )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkogg "${_IMPORT_PREFIX}/lib/vtkogg-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkogg-8.2.dll" )

# Import target "vtktheora" for configuration "Debug"
set_property(TARGET vtktheora APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtktheora PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtktheora-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtktheora-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtktheora )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtktheora "${_IMPORT_PREFIX}/lib/vtktheora-8.2.lib" "${_IMPORT_PREFIX}/bin/vtktheora-8.2.dll" )

# Import target "vtkIOMovie" for configuration "Debug"
set_property(TARGET vtkIOMovie APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOMovie PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOMovie-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonMisc;vtkCommonSystem"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOMovie-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOMovie )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOMovie "${_IMPORT_PREFIX}/lib/vtkIOMovie-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOMovie-8.2.dll" )

# Import target "vtkIOPLY" for configuration "Debug"
set_property(TARGET vtkIOPLY APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOPLY PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOPLY-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonMisc;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOPLY-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOPLY )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOPLY "${_IMPORT_PREFIX}/lib/vtkIOPLY-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOPLY-8.2.dll" )

# Import target "vtkIOParallelNetCDF" for configuration "Debug"
set_property(TARGET vtkIOParallelNetCDF APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOParallelNetCDF PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOParallelNetCDF-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkParallelMPI;vtknetcdf"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOParallelNetCDF-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOParallelNetCDF )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOParallelNetCDF "${_IMPORT_PREFIX}/lib/vtkIOParallelNetCDF-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOParallelNetCDF-8.2.dll" )

# Import target "vtkTestingIOSQL" for configuration "Debug"
set_property(TARGET vtkTestingIOSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkTestingIOSQL PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkTestingIOSQL-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkTestingIOSQL-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkTestingIOSQL )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkTestingIOSQL "${_IMPORT_PREFIX}/lib/vtkTestingIOSQL-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkTestingIOSQL-8.2.dll" )

# Import target "vtkIOSegY" for configuration "Debug"
set_property(TARGET vtkIOSegY APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOSegY PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOSegY-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOSegY-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOSegY )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOSegY "${_IMPORT_PREFIX}/lib/vtkIOSegY-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOSegY-8.2.dll" )

# Import target "vtkIOTecplotTable" for configuration "Debug"
set_property(TARGET vtkIOTecplotTable APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOTecplotTable PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOTecplotTable-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkIOCore;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOTecplotTable-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOTecplotTable )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOTecplotTable "${_IMPORT_PREFIX}/lib/vtkIOTecplotTable-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOTecplotTable-8.2.dll" )

# Import target "vtkIOVeraOut" for configuration "Debug"
set_property(TARGET vtkIOVeraOut APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOVeraOut PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOVeraOut-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkhdf5_src;vtkhdf5_hl_src"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOVeraOut-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOVeraOut )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOVeraOut "${_IMPORT_PREFIX}/lib/vtkIOVeraOut-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOVeraOut-8.2.dll" )

# Import target "vtkIOVideo" for configuration "Debug"
set_property(TARGET vtkIOVideo APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkIOVideo PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkIOVideo-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonSystem;vtksys"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkIOVideo-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkIOVideo )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkIOVideo "${_IMPORT_PREFIX}/lib/vtkIOVideo-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkIOVideo-8.2.dll" )

# Import target "vtkImagingStatistics" for configuration "Debug"
set_property(TARGET vtkImagingStatistics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingStatistics PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingStatistics-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkImagingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingStatistics-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingStatistics )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingStatistics "${_IMPORT_PREFIX}/lib/vtkImagingStatistics-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingStatistics-8.2.dll" )

# Import target "vtkRenderingImage" for configuration "Debug"
set_property(TARGET vtkRenderingImage APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingImage PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingImage-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonMath;vtkCommonTransforms;vtkImagingCore"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingImage-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingImage "${_IMPORT_PREFIX}/lib/vtkRenderingImage-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingImage-8.2.dll" )

# Import target "vtkImagingMorphological" for configuration "Debug"
set_property(TARGET vtkImagingMorphological APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkImagingMorphological PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkImagingMorphological-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkImagingSources"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkImagingMorphological-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkImagingMorphological )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkImagingMorphological "${_IMPORT_PREFIX}/lib/vtkImagingMorphological-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkImagingMorphological-8.2.dll" )

# Import target "vtkRenderingLOD" for configuration "Debug"
set_property(TARGET vtkRenderingLOD APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingLOD PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingLOD-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkCommonSystem;vtkFiltersCore;vtkFiltersModeling"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingLOD-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingLOD )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingLOD "${_IMPORT_PREFIX}/lib/vtkRenderingLOD-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingLOD-8.2.dll" )

# Import target "vtkRenderingQt" for configuration "Debug"
set_property(TARGET vtkRenderingQt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkRenderingQt PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkRenderingQt-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonSystem;vtkFiltersSources;vtkFiltersTexture;vtkGUISupportQt;Qt5::Widgets"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkRenderingQt-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkRenderingQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkRenderingQt "${_IMPORT_PREFIX}/lib/vtkRenderingQt-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingQt-8.2.dll" )

# Import target "vtkViewsQt" for configuration "Debug"
set_property(TARGET vtkViewsQt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkViewsQt PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkViewsQt-8.2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "vtkCommonDataModel;vtkCommonExecutionModel;vtkFiltersExtraction;vtkFiltersGeneral;vtkInfovisCore;Qt5::Widgets"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkViewsQt-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkViewsQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkViewsQt "${_IMPORT_PREFIX}/lib/vtkViewsQt-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkViewsQt-8.2.dll" )

# Import target "vtkLocalExample" for configuration "Debug"
set_property(TARGET vtkLocalExample APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkLocalExample PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/vtkLocalExample-8.2.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/vtkLocalExample-8.2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkLocalExample )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkLocalExample "${_IMPORT_PREFIX}/lib/vtkLocalExample-8.2.lib" "${_IMPORT_PREFIX}/bin/vtkLocalExample-8.2.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
