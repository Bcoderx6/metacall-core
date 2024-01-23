/*
 *	Reflect Library by Parra Studios
 *	A library for provide reflection and metadata representation.
 *
 *	Copyright (C) 2016 - 2024 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 */

#ifndef REFLECT_ATTRIBUTE_DECL_H
#define REFLECT_ATTRIBUTE_DECL_H 1

#ifdef __cplusplus
extern "C" {
#endif

struct attribute_type;

typedef void *attribute_impl;

typedef struct attribute_type *attribute;

typedef void (*attribute_impl_interface_destroy)(attribute, attribute_impl);

typedef struct attribute_interface_type
{
	attribute_impl_interface_destroy destroy;

} * attribute_interface;

typedef attribute_interface (*attribute_impl_interface_singleton)(void);

#ifdef __cplusplus
}
#endif

#endif /* REFLECT_ATTRIBUTE_DECL_H */
