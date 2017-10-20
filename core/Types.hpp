// @v 1.3.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once

// Header
#define MT_VERSION_1_3_0
// Header

using i64 = long long;
using i32 = long;
using i16 = short;
using i8  = char;

using u64 = unsigned long long;
using u32 = unsigned long;
using u16 = unsigned short;
using u8  = unsigned char;

using f64 = double;
using f32 = float;

using utf8Char = unsigned char;

using FileHandle = int;
using DirHandle = int;

#define MAX_i64  9223372036854775807
#define MAX_i32  4294967295
#define MAX_i16  32767
#define MAX_i8   127

#define MIN_i64  -9223372036854775807
#define MIN_i32  -2147483648
#define MIN_i16  -32768
#define MIN_i8   -128


#ifdef MT_SPECIAL_DEF
#define func auto
#define $ T
#define typed template<typename T>
#define strc class
#define var  auto
#define let  const auto
#endif
