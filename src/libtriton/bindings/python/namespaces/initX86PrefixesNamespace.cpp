//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the LGPLv3 License.
*/

#ifdef TRITON_PYTHON_BINDINGS

#include <api.hpp>
#include <pythonBindings.hpp>
#include <pythonUtils.hpp>
#include <x86Specifications.hpp>



/*! \page py_PREFIX_page PREFIX
    \brief [**python api**] All information about the PREFIX python namespace.

\tableofcontents

\section PREFIX_py_description Description
<hr>

According to the CPU architecture, the PREFIX namespace contains all kinds of instruction prefixes.

\section PREFIX_py_api Python API - Items of the PREFIX namespace
<hr>

\subsection PREFIX_x86_py_api x86 and x86_64

- **PREFIX.INVALID**<br>
- **PREFIX.LOCK**<br>
- **PREFIX.REP**<br>
- **PREFIX.REPNE**<br>

*/


namespace triton {
  namespace bindings {
    namespace python {

      void initX86PrefixesNamespace(void) {
        if (!triton::bindings::python::initialized)
          return;

        PyDict_Clear(triton::bindings::python::prefixesDict);

        PyDict_SetItemString(triton::bindings::python::prefixesDict, "INVALID", PyLong_FromUint(triton::arch::x86::ID_PREFIX_INVALID));
        PyDict_SetItemString(triton::bindings::python::prefixesDict, "LOCK",    PyLong_FromUint(triton::arch::x86::ID_PREFIX_LOCK));
        PyDict_SetItemString(triton::bindings::python::prefixesDict, "REP",     PyLong_FromUint(triton::arch::x86::ID_PREFIX_REP));
        PyDict_SetItemString(triton::bindings::python::prefixesDict, "REPNE",   PyLong_FromUint(triton::arch::x86::ID_PREFIX_REPNE));
      }

    }; /* python namespace */
  }; /* bindings namespace */
}; /* triton namespace */

#endif /* TRITON_PYTHON_BINDINGS */
