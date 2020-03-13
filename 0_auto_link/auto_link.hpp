// IMC Libs auto linking supported with MSVS
// This follows how Boost does its autolinking

#ifndef CATCH2_LIB_CONFIG_H
	#include "config.hpp"
#endif

#ifndef CATCH2_LIB_NAME
	#error "Macro LIB_NAME not set (internal error)"
#endif

#if (_MSC_VER>=1200)
// Boost goes back to only VS12 and these libraries uses C++11 features anyway

	#  if defined(_MSC_VER) && (_MSC_VER < 1200)
	// Note: no compilers before 1200 are supported
	#  elif defined(_MSC_VER) && (_MSC_VER < 1300)

	#    ifdef UNDER_CE
	// eVC4:
	#      define CATCH2_LIB_TOOLSET "evc4"
	#    else
	// vc6:
	#      define CATCH2_LIB_TOOLSET "vc6"
	#    endif

	#  elif defined(_MSC_VER) && (_MSC_VER < 1310)

	// vc7:
	#    define CATCH2_LIB_TOOLSET "vc7"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1400)

	// vc71:
	#    define CATCH2_LIB_TOOLSET "vc71"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1500)

	// vc80:
	#    define CATCH2_LIB_TOOLSET "vc80"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1600)

	// vc90:
	#    define CATCH2_LIB_TOOLSET "vc90"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1700)

	// vc10:
	#    define CATCH2_LIB_TOOLSET "vc100"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1800)

	// vc11:
	#    define CATCH2_LIB_TOOLSET "vc110"

	#  elif defined(_MSC_VER) && (_MSC_VER < 1900)

	// vc12:

	// AN Note: updated from boost auto_link.hpp, I guess MSVC versioning by M$ got confused??

	#    define CATCH2_LIB_TOOLSET "vc120"
	
	#  elif defined(_MSC_VER) && (_MSC_VER < 1910)

	// vc14:
	#    define CATCH2_LIB_TOOLSET "vc140"

	// AN Note: modified to 1930 per https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019, std:c++20 is _MSC_VER = 1930 I think??
	#  elif defined(_MSC_VER) && (_MSC_VER < 1930)

		 // vc14.1:
	#    define CATCH2_LIB_TOOLSET "vc141"

	#  elif defined(_MSC_VER)

		 // vc14.2:
	#    define CATCH2_LIB_TOOLSET "vc142"

	/*
	#  elif defined(__BORLANDC__)

		 // CBuilder 6:
	#    define CATCH2_LIB_TOOLSET "bcb"

	#  elif defined(__ICL)

		 // Intel C++, no version number:
	#    define CATCH2_LIB_TOOLSET "iw"

	#  elif defined(__MWERKS__) && (__MWERKS__ <= 0x31FF )

		 // Metrowerks CodeWarrior 8.x
	#    define CATCH2_LIB_TOOLSET "cw8"

	#  elif defined(__MWERKS__) && (__MWERKS__ <= 0x32FF )

		 // Metrowerks CodeWarrior 9.x
	#    define CATCH2_LIB_TOOLSET "cw9"

	#  elif defined(BOOST_CLANG) && defined(BOOST_WINDOWS) && defined(_MSC_VER) && (__clang_major__ >= 4)

		 // Clang on Windows
	#    define CATCH2_LIB_TOOLSET "clangw" BOOST_STRINGIZE(__clang_major__)
	/**/
	
	#  endif

// select thread opt
#if defined(_MT) || defined (__MT__)
#define CATCH2_LIB_THREAD_OPT "-mt"
#endif

//
#if defined(_WIN64)
	#define CATCH2_LIB_BIT_ARCH "x64"
#elif defined(_WIN32)
	#define CATCH2_LIB_BIT_ARCH "x86"
#endif

// debug/release Flag - CATCH2_LIB relies on MSVS to name .dll/.lib per its variables
#if defined(_DEBUG)
	#define CATCH2_LIB_CONFIG_OPT "Debug"
#else
	#define CATCH2_LIB_CONFIG_OPT "Release"
#endif

#ifdef _DLL
	
#else
	#define LIB_PREFIX "lib"
	#define FILE_EXT ".lib"
#endif

#endif

// Inform MSVC compiler to link file
#if defined(_MSC_VER)\
	&& defined(CATCH2_LIB_TOOLSET)\
	&& defined(CATCH2_LIB_THREAD_OPT)\
	&& defined(CATCH2_LIB_BIT_ARCH)\
	&& defined(CATCH2_LIB_CONFIG_OPT)\
	&& defined (CATCH2_LIB_VERSION)
// added hypen before CATCH2_LIB_TOOLSET, boost took it out??
#  pragma comment(lib, CATCH2_LIB_STRINGIZE(CATCH2_LIB_NAME) "-" CATCH2_LIB_TOOLSET "-" CATCH2_LIB_BIT_ARCH "-" CATCH2_LIB_CONFIG_OPT "-" CATCH2_LIB_VERSION ".lib")
#     pragma message ("Linking to lib file: " CATCH2_LIB_STRINGIZE(CATCH2_LIB_NAME) "-" CATCH2_LIB_TOOLSET "-" CATCH2_LIB_BIT_ARCH "-" CATCH2_LIB_CONFIG_OPT "-" CATCH2_LIB_VERSION ".lib")
#endif

#if defined(CATCH2_LIB_NAME)
	#undef CATCH2_LIB_NAME
#endif
#if defined(CATCH2_LIB_THREAD_OPT)
	#undef CATCH2_LIB_THREAD_OPT
#endif
#if defined(CATCH2_LIB_CONFIG_OPT)
	#undef CATCH2_LIB_CONFIG_OPT
#endif