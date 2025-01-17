// -*- C++ -*-

//=============================================================================
/**
 *  @file    Operation_Table_Binary_Search.h
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================

#ifndef TAO_OPERATION_TABLE_BINARY_SEARCH_H
#define TAO_OPERATION_TABLE_BINARY_SEARCH_H

#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Operation_Table.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_Binary_Search_OpTable
 *
 * @brief Helper class for using binary search operatin lookup strategy
 * in the server skeletons.
 *
 * This class declares pure virtual method called 'lookup ()'
 * which will be generated by the GPERF program. This method is
 * used by 'bind ()' and 'find ()' methods. Subclasses will
 * define the lookup method.
 */
class TAO_PortableServer_Export TAO_Binary_Search_OpTable
  : public TAO_Operation_Table
{
public:
  /// Do nothing destructor.
  virtual ~TAO_Binary_Search_OpTable ();

  /// See the documentation in the base class for details.
  virtual int find (const char *opname,
                    TAO_Skeleton &skelfunc,
                    const unsigned int length = 0);

  virtual int find (const char *opname,
                    TAO_Collocated_Skeleton &skelfunc,
                    TAO::Collocation_Strategy s,
                    const unsigned int length = 0);

  virtual int bind (const char *opname,
                    const TAO::Operation_Skeletons skel_ptr);

private:
  /// Method that should defined by the subclasses. GPERF program
  /// will generate this routine routines.
  virtual const TAO_operation_db_entry* lookup (const char *str) = 0;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TAO_OPERATION_TABLE_BINARY_SEARCH_H */
