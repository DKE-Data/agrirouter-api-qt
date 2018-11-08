//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef CCIAGRIROUTER_EXPORT_7DD79085826742808536F44283DFCA3D
#define CCIAGRIROUTER_EXPORT_7DD79085826742808536F44283DFCA3D

/**
    This file contains the export/import macro definitions.
*/

#include <QtCore/qglobal.h>

#if defined(BUILDING_CCIAGRIROUTER)
#  define CCIAGRIROUTER_EXPORT Q_DECL_EXPORT
#else
#  define CCIAGRIROUTER_EXPORT Q_DECL_IMPORT
#endif

#endif//CCIAGRIROUTER_EXPORT_7DD79085826742808536F44283DFCA3D
