// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#include <vespa/document/base/field.h>
#include <vespa/document/update/clearvalueupdate.h>
#include <vespa/document/fieldvalue/document.h>
#include <vespa/vespalib/util/exceptions.h>

using vespalib::IllegalArgumentException;
using vespalib::IllegalStateException;

namespace document
{

IMPLEMENT_IDENTIFIABLE(ClearValueUpdate, ValueUpdate);

bool
ClearValueUpdate::operator==(const ValueUpdate& other) const
{
    return (other.getClass().id() == ClearValueUpdate::classId);
}

// Ensure that this update is compatible with given field.
void
ClearValueUpdate::checkCompatibility(const Field&) const
{
}

// Apply this update to the given document.
bool
ClearValueUpdate::applyTo(FieldValue& value) const
{
    (void) value;
    return false;
}

void
ClearValueUpdate::printXml(XmlOutputStream& xos) const
{
    xos << XmlTag("clear") << XmlEndTag();
}

// Print this update in human readable form.
void
ClearValueUpdate::print(std::ostream& out, bool, const std::string&) const
{
    out << "ClearValueUpdate()";
}

// Deserialize this update from the given buffer.
void
ClearValueUpdate::deserialize(const DocumentTypeRepo&, const DataType&,
                             ByteBuffer&, uint16_t)
{
}

}
