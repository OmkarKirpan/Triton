//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the LGPLv3 License.
*/

#ifndef TRITON_SYMBOLICVARIABLE_H
#define TRITON_SYMBOLICVARIABLE_H

#include <string>

#include "symbolicEnums.hpp"
#include "tritonTypes.hpp"



//! \module The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  //! \module The Engines namespace
  namespace engines {
  /*!
   *  \ingroup triton
   *  \addtogroup engines
   *  @{
   */

    //! \module The Symbolic Execution namespace
    namespace symbolic {
    /*!
     *  \ingroup engines
     *  \addtogroup symbolic
     *  @{
     */

      /*! \class SymbolicVariable
          \brief The symbolic variable class. */
      class SymbolicVariable {

        protected:

          //! The symbolic variable kind. \sa triton::engines::symbolic::symkind_e
          symkind_e symVarKind;

          //! The comment of the symbolic variable.
          std::string symVarComment;

          //! The name of the symbolic variable. \sa TRITON_SYMVAR_NAME
          std::string symVarName;

          //! The id of the symbolic variable. This id is unique.
          triton::__uint symVarId;

          //! The kind value of the symbolic variable.
          /*!
            \brief If the symbolic varialbe is a triton::engines::symbolic::REG, this value contains the register ID.
            \biref If the symbolic varialbe is a triton::engines::symbolic::MEM, this value contains the memory access' address.
          */
          triton::__uint symVarKindValue;

          //! The size (in bits) of the symbolic variable.
          triton::uint32 symVarSize;

          //! The concrete value of the symbolic variable.
          triton::uint128 symVarConcreteValue;

        public:

          //! Constructor.
          SymbolicVariable(symkind_e kind, triton::__uint kindValue, triton::__uint id, triton::uint32 size, std::string comment, triton::uint128 concreteValue=0);

          //! Constructor by copy.
          SymbolicVariable(const SymbolicVariable &copy);

          //! Destructore.
          ~SymbolicVariable();

          //! Returns the symbolic variable kind. \sa triton::engines::symbolic::symkind_e.
          symkind_e getSymVarKind(void);

          //! Returns the comment of the symbolic variable.
          std::string& getSymVarComment(void);

          //! Returns the name of the symbolic variable.
          std::string& getSymVarName(void);

          //! Returns the id of the symbolic variable. This id is unique.
          triton::__uint getSymVarId(void);

          //! Returns the kind value of the symbolic variable.
          triton::__uint getSymVarKindValue(void);

          //! Returns the size (in bits) of the symbolic variable.
          triton::uint32 getSymVarSize(void);

          //! Returns the concrete value (if exists) of the symbolic variable.
          triton::uint128 getConcreteValue(void);

          //! Sets the comment of the symbolic variable.
          void setSymVarComment(std::string comment);

          //! Sets the concrete value of the symbolic variable.
          void setSymVarConcreteValue(triton::uint128 value);
      };

      //! Displays a symbolic variable.
      std::ostream& operator<<(std::ostream& stream, SymbolicVariable symVar);

      //! Displays a symbolic variable.
      std::ostream& operator<<(std::ostream& stream, SymbolicVariable* symVar);

    /*! @} End of symbolic namespace */
    };
  /*! @} End of engines namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_SYMBOLICVARIABLE_H */

