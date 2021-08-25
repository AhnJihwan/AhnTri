/* Copyright 2021 Jihwan Ahn.

This is a part of ANTCLIB.

   Copyright 2021 Jihwan Ahn

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
   */
   
#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef 				__cplusplus
#define bool			_Bool
#define true			1
#define false			0

#else

/*Defineing _Bool as GNU C++ extension*/
#define _Bool		bool

#if __cplusplus < 201103L
#define bool 			bool	//GNU extention
#define true			true	//GNU extension
#define false			false	//GNU extention
#define yes			true	//Ant C library Feature
#define no			false	//Ant C library Feature
#endif

#endif

#define __bool_true_false_are_defined	1

#endif
