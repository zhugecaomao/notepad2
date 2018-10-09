#include "EditLexer.h"
#include "EditStyle.h"

// http://www.jrsoftware.org/isinfo.php

static KEYWORDLIST Keywords_INNO = {{
"code components custommessages dirs files icons ini installdelete langoptions languages messages "
"registry run setup types tasks uninstalldelete uninstallrun _istool"

, // 1
"allowcancelduringinstall allownetworkdrive allownoicons allowrootdirectory allowuncpath alwaysrestart alwaysshowcomponentslist "
"alwaysshowdironreadypage alwaysshowgrouponreadypage alwaysusepersonalgroup appcomments appcontact appcopyright "
"appenddefaultdirname appenddefaultgroupname appid appmodifypath appmutex appname apppublisher apppublisherurl "
"appreadmefile appsupportphone appsupporturl appupdatesurl appvername appversion architecturesallowed "
"architecturesinstallin64bitmode backcolor backcolor2 backcolordirection backsolid beveledlabel changesassociations "
"changesenvironment compression compressionthreads copyrightfontname copyrightfontsize createappdir "
"createuninstallregkey defaultdirname defaultgroupname defaultuserinfoname defaultuserinfoorg defaultuserinfoserial "
"dialogfontname dialogfontsize direxistswarning disabledirpage disablefinishedpage disableprogramgrouppage disablereadymemo "
"disablereadypage disablestartupprompt diskclustersize diskslicesize diskspanning enabledirdoesntexistwarning disablewelcomepage "
"encryption extradiskspacerequired flatcomponentslist infoafterfile infobeforefile internalcompresslevel "
"languagedetectionmethod languagecodepage languageid languagename licensefile lzmaalgorithm lzmablocksize "
"lzmadictionarysize lzmamatchfinder lzmanumblockthreads lzmanumfastbytes lzmauseseparateprocess mergeduplicatefiles "
"minversion onlybelowversion outputbasefilename outputdir outputmanifestfile password privilegesrequired reservebytes "
"restartifneededbyrun righttoleft setupiconfile setuplogging showcomponentsizes showlanguagedialog showtaskstreelines "
"showundisplayablelanguages signeduninstaller signeduninstallerdir signtool slicesperdisk solidcompression sourcedir "
"strongassemblyname timestamprounding timestampsinutc titlefontname titlefontsize touchdate touchtime uninstallable "
"uninstalldisplayicon uninstalldisplayname uninstallfilesdir uninstalldisplaysize uninstalllogmode uninstallrestartcomputer "
"updateuninstalllogappname usepreviousappdir usepreviousgroup usepreviouslanguage useprevioussetuptype useprevioustasks "
"verb versioninfoproductname useprevioususerinfo userinfopage usesetupldr versioninfocompany versioninfocopyright "
"versioninfodescription versioninfoproductversion versioninfotextversion versioninfoversion versioninfoproducttextversion "
"welcomefontname welcomefontsize windowshowcaption windowstartmaximized windowresizable windowvisible wizardimagebackcolor "
"wizardimagefile wizardimagestretch wizardsmallimagefile"

, // 2
"appusermodelid afterinstall attribs beforeinstall check comment components copymode description destdir destname excludes "
"extradiskspacerequired filename flags fontinstall groupdescription hotkey infoafterfile infobeforefile iconfilename "
"iconindex key languages licensefile messagesfile minversion name onlybelowversion parameters permissions root runonceid "
"section source statusmsg string subkey tasks terminalservicesaware type types valuedata valuename valuetype workingdir"

, // 3 Preprocessor
"append define dim else emit elif endif endsub error expr file for if "
"ifdef ifexist ifndef ifnexist include insert pragma sub undef"

, // 4 Pascal Keyword
"and begin break case const continue do downto else end except finally for function "
"if not of or procedure repeat then to try type until uses var while with interface record"

, NULL, NULL, NULL, NULL

, NULL, NULL, NULL, NULL, NULL, NULL, NULL
}};


EDITLEXER lexINNO = { SCLEX_INNOSETUP, NP2LEX_INNO, EDITLEXER_HOLE(L"Inno Setup Script"), L"iss; isl; islu", &Keywords_INNO,
{
	EDITSTYLE_DEFAULT,
	{ MULTI_STYLE(SCE_INNO_COMMENT, SCE_INNO_COMMENT_PASCAL, 0, 0), NP2STYLE_Comment, EDITSTYLE_HOLE(L"Comment"), L"fore:#008000" },
	{ SCE_INNO_KEYWORD, NP2STYLE_Keyword, EDITSTYLE_HOLE(L"Keyword"), L"fore:#0000FF" },
	{ SCE_INNO_PREPROC, NP2STYLE_Preprocessor, EDITSTYLE_HOLE(L"Preprocessor"), L"fore:#FF8000" },
	{ SCE_INNO_KEYWORD_PASCAL, 63501, EDITSTYLE_HOLE(L"Pascal Keyword"), L"fore:#0000FF" },
	//{ SCE_INNO_PAS_TYPE, NP2STYLE_TypeKeyword, EDITSTYLE_HOLE(L"Pascal Type Keyword"), L"bold; fore:#1E90FF" },
	{ SCE_INNO_SECTION, 63502, EDITSTYLE_HOLE(L"Section"), L"bold; fore:#000080; back:#FF8000; eolfilled" },
	{ SCE_INNO_PARAMETER, 63503, EDITSTYLE_HOLE(L"Parameter"), L"fore:#0000FF" },
	{ SCE_INNO_INLINE_EXPANSION, 63504, EDITSTYLE_HOLE(L"Inline Expansion"), L"fore:#800080" },
	{ MULTI_STYLE(SCE_INNO_STRING_DOUBLE, SCE_INNO_STRING_SINGLE, 0, 0), NP2STYLE_String, EDITSTYLE_HOLE(L"String"), L"fore:#808000" },
	//{ SCE_INNO_NUMBER, NP2STYLE_Number, EDITSTYLE_HOLE(L"Number"), L"fore:#FF0000" },
	//{ SCE_INNO_OPERATOR, NP2STYLE_Operator, EDITSTYLE_HOLE(L"Operator"), L"fore:#B000B0" },
	EDITSTYLE_SENTINEL
}
};

