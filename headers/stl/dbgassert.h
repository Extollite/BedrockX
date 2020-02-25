#pragma once
#ifdef DEBUG
#define dbg_assert(x) assert(x)
#else
#define dbg_assert(x)  
#endif