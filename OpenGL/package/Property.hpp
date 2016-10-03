#pragma once

#define Property_Get(type,name) __declspec(property(get=_get_##name))type name;\
type _get_##name()
