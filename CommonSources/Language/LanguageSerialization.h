﻿//	/*
// 	*
// 	* Copyright (C) 2003-2010 Alexandros Economou
//	*
//	* This file is part of Jaangle (http://www.jaangle.com)
// 	*
// 	* This Program is free software; you can redistribute it and/or modify
// 	* it under the terms of the GNU General Public License as published by
// 	* the Free Software Foundation; either version 2, or (at your option)
// 	* any later version.
// 	*
// 	* This Program is distributed in the hope that it will be useful,
// 	* but WITHOUT ANY WARRANTY; without even the implied warranty of
// 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// 	* GNU General Public License for more details.
// 	*
// 	* You should have received a copy of the GNU General Public License
// 	* along with GNU Make; see the file COPYING. If not, write to
// 	* the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
// 	* http://www.gnu.org/copyleft/gpl.html
// 	*
//	*/ 
#ifndef _LanguageSerialization_H
#define _LanguageSerialization_H


#include "ILanguage.h"

//1. Load/Saves lng Files


class LanguageSerialization
{
public:
	static BOOL ImportLngFile(LPCTSTR pathName, ILanguage& destLanguage, BOOL bInfoOnly = FALSE);
	static BOOL ExportLngFile(LPCTSTR pathName, ILanguage* pSrcLanguage, ILanguage* pReferenceLanguage);

private:
	static LPTSTR GetLanguageFile(LPCTSTR pathName);
	static BOOL GetLanguageStrings(LPCTSTR langFileData, ILanguage& destLanguage);
	static BOOL GetLanguageInfo(LPCTSTR langFileData, LanguageInfo& languageInfo);
	static void Replace(std::tstring& str, LPCTSTR oldString, LPCTSTR newString);
	static void FixString(std::tstring& str);
	static void SaveHeader(CFile& f, LPCTSTR header, LPCTSTR info);
};


#endif
