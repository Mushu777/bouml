// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
//
// This file is part of the BOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : bouml@free.fr
// home   : http://bouml.free.fr
//
// *************************************************************************

#ifndef UMLCLASSMEMBER_H
#define UMLCLASSMEMBER_H

#include "UmlBaseClassMember.h"

// This class globaly manages class's operations, relations, attributes
// and sub-classes
// You can modify it as you want (except the constructor)

class UmlClassMember : public UmlBaseClassMember {
  public:
    UmlClassMember(void * id, const QCString & n)
      : UmlBaseClassMember(id, n) {};
    
    static void remove_comments(QCString & s);
    static void remove_arrays(QCString & s);
    static void remove_preprocessor(QCString & s);
    static bool compute_dependency(QList<CppRefType> & dependency,
				   QCString decl, const UmlTypeSpec &,
				   bool force_incl = FALSE);

    void generate_visibility(aVisibility & current_visibility,
			     QTextOStream & f_h, bool ahead,
			     const QCString & indent);
    bool insert_template(const char *& p, QTextOStream & fs,
			 const QCString & indent, const QCString & templ);
};

#endif
