/**
 *	RRThreadManager.hpp
 *	Author - Corbin Matschull <basedjux>
 *	License - GPLv3
 *	2016
 *
 *	
 *	Dispatches a single thread instance based upon call
 *	
 *	Thread Creation -
 *	
 *		Signature -
 *			RThreadManager::CreateInstance(size_t *allocSize, 
 *										   bool hasCallSignature,
 *										   DWORD callGUID)
 *		
 *		Params -
 *			allocSize -- Size of the allocation given by normal ISO standard (size_t = void)
 *			hasCallSignature -- Allows for external call signatures outside of the call scope
 *			callGUID - GUID of the call (generates via smallUtils.h)
 *		
 *		Returns -
 *			Created thread instance
 *
 */
#pragma once


#include <Windows.h>
#include <cstdio>
#include <vector>


namespace rrmanager
{

#ifndef ___RR_Manager_Create_Base_Pointer
#	define ___RR_Manager_Create_Base_Pointer 1
#endif

	enum CA_Base
	{
		//	Core allocator unlock
		/**
		 * Sends flag to RABaseAllocator::ReceiveSig() and unlocks the base pointer for more data
		 */
		CA_UNLOCKED = 0x01C,

		//	Core allocator lock
		/**
		 * Sends flag to RABaseAllocator::ReceiveSig() and lock the base pointer to disallow more data
		 */
		CA_LOCKED   = 0x01D,
	};

	struct _IMAllocator_Base
	{

		//	Bottom of the allocator stack
		std::vector<size_t> _AllocatorBase;

		//	Top of the allocator stack
		std::vector<size_t> _AllocatorCap;

		//	Allows mutex'd threads to read and store multiple log streams
		BOOL				_AllowMultithreadRead;
	};


	class RRThread
	{
		
	};
}
