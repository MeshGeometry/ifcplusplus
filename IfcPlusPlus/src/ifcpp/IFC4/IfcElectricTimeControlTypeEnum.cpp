/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcElectricTimeControlTypeEnum.h"

// TYPE IfcElectricTimeControlTypeEnum = ENUMERATION OF	(TIMECLOCK	,TIMEDELAY	,RELAY	,USERDEFINED	,NOTDEFINED);
IfcElectricTimeControlTypeEnum::IfcElectricTimeControlTypeEnum() {}
IfcElectricTimeControlTypeEnum::~IfcElectricTimeControlTypeEnum() {}
shared_ptr<IfcPPObject> IfcElectricTimeControlTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcElectricTimeControlTypeEnum> copy_self( new IfcElectricTimeControlTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcElectricTimeControlTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCELECTRICTIMECONTROLTYPEENUM("; }
	if( m_enum == ENUM_TIMECLOCK )
	{
		stream << ".TIMECLOCK.";
	}
	else if( m_enum == ENUM_TIMEDELAY )
	{
		stream << ".TIMEDELAY.";
	}
	else if( m_enum == ENUM_RELAY )
	{
		stream << ".RELAY.";
	}
	else if( m_enum == ENUM_USERDEFINED )
	{
		stream << ".USERDEFINED.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcElectricTimeControlTypeEnum> IfcElectricTimeControlTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcElectricTimeControlTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcElectricTimeControlTypeEnum>(); }
	shared_ptr<IfcElectricTimeControlTypeEnum> type_object( new IfcElectricTimeControlTypeEnum() );
	if( boost::iequals( arg, L".TIMECLOCK." ) )
	{
		type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_TIMECLOCK;
	}
	else if( boost::iequals( arg, L".TIMEDELAY." ) )
	{
		type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_TIMEDELAY;
	}
	else if( boost::iequals( arg, L".RELAY." ) )
	{
		type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_RELAY;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcElectricTimeControlTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
