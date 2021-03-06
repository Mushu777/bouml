
#include "UmlActualParameter.h"
#include "FileOut.h"
#include "UmlClass.h"

void UmlActualParameter::write(FileOut & out, UmlClass * cl, int actualrank) const {
  out.indent();
  out << "<parameterSubstitution xmi:type=\"uml:TemplateParameterSubstitution\"";
  out.id_prefix(cl, "ACTUALPARAM", actualrank);
  out << ">\n";
  out.indent();
  out << "\t<formal";
  out.idref_prefix(superClass(), "TEMPLPARAM", rank());
  out << "/>\n";

  out.indent();
  if (value().type != 0) {
    out << "\t<actual";
    out.idref(value().type);
    out << "/>\n";
  }
  else {
    // produce an opaque expression, even in case of primitive type
    out << "\t<actual";
    out.idref_prefix(cl, "OPAQUE_ACTUAL", actualrank);
    out << "/>\n";
    
    out.indent();
    out << "\t<ownedActual xmi:type=\"uml:OpaqueExpression\"";
    out.id_prefix(cl, "OPAQUE_ACTUAL", actualrank);
    out << " body=\"";
    out.quote(value().explicit_type);
    out << "\"/>\n";
  }

  out.indent();
  out << "</parameterSubstitution>\n";
}

