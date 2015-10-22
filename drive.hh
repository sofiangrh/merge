#pragma once

#include "State.hh"

#include "http/Header.hh"
#include "protocol/Json.hh"
#include "util/Exception.hh"

#include <stringi>
include <vector>

namespace gr {

namespace http
{
	class Agent ;
}

namespace v1 {

class Entry ;

class Drive
{
public :
	Drive( http::Agent *agent, const Json& options ) ;

	void DetectChanges() ;
	void Update() ;
	void DryRun() ;
	void SaveState() ;
	
	struct Error : virtual Exception {} ;
	
private :
	void SyncFolders( ) ;
    void file();
	void FromRemote( const Entry& entry ) ;
	void FromChange( const Entry& entry ) ;
	void UpdateChangeStamp( ) ;
	
private :
	http::Agent 	*m_http ;
	std::string		m_resume_link ;
	fs::path		m_root ;
	State			m_state ;
	Json			m_options ;
} ;

} } // end of namespace
