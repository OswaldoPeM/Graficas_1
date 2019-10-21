/********************************************************************/
/**
* @file   soModule.h
* @author Oswaldo Perez Macias
* @date   19/10/2019
* @brief  Represents one engine module
*
* Represents one engine module. Essentially it is a specialized type
* of singleton. Module must be manually started up and shut down
* before and after use.
*
* @bug	   No known bugs.
*/
/********************************************************************/
#pragma once

/************************************************************************************************************************/
/* Includes                                                                     										*/
/************************************************************************************************************************/
#include <iostream>

/************************************************************************************************************************/
/**
* @brief	Represents one engine module. Essentially it is a specialized type of singleton. Module must be manually
*			started up and shut down before and after use.
*/
/************************************************************************************************************************/
template <class T>
class RModule
{
public:
	/************************************************************************************************************************/
	/**
	* @brief	Returns a reference to the module instance. Module has to have been started up first otherwise an exception
	*			will be thrown.
	*/
	/************************************************************************************************************************/
	static T& Instance()
	{
		if (IsShutDown())
		{
			std::cout << "soModule", "Instance()", "Trying to access a module but it hasn't been started up yet.";
		}

		if (IsDestroyed())
		{
			std::cout << "soModule", "Instance()", "Trying to access a destroyed module.";
		}

		return *_Instance();
	}

	/************************************************************************************************************************/
	/**
	* @brief	Returns a pointer to the module instance. Module has to have been started up first otherwise an exception
	*			will be thrown.
	*/
	/************************************************************************************************************************/
	static T* InstancePtr()
	{
		if (IsShutDown())
		{
			std::cout << "soModule", "InstancePtr()", "Trying to access a module but it hasn't been started up yet.";
			return NULL;
		}

		if (IsDestroyed())
		{
			std::cout << "soModule", "InstancePtr()", "Trying to access a destroyed module.";
			return NULL;
		}

		return _Instance();
	}

	/************************************************************************************************************************/
	/**
	* @brief	Constructs and starts the module using the specified parameters.
	*/
	/************************************************************************************************************************/
	static unsigned int StartUp(void* _Desc)
	{
		if (!IsShutDown())
		{
			std::cout << "soModule", "StartUp()", "Trying to start an already started module.";
			return EC_FALSE;
		}

		_Instance() = new T;
		IsShutDown() = false;

		return ((RModule*)_Instance())->OnStartUp(_Desc);
	}

	/************************************************************************************************************************/
	/**
	* @brief	Shuts down this module and frees any resources it is using.
	*/
	/************************************************************************************************************************/
	static void ShutDown()
	{
		if (IsShutDown())
		{
			std::cout << "soModule", "ShutDown()", "Trying to shut down an already shut down module.";
			return;
		}

		((RModule*)_Instance())->OnShutDown();

		delete(_Instance());
		IsShutDown() = true;
	}

	/************************************************************************************************************************/
	/**
	* @brief	Query if the module has been started.
	*/
	/************************************************************************************************************************/
	static bool IsStarted()
	{
		return !IsShutDown() && !IsDestroyed();
	}

protected:
	RModule()
	{
	}

	virtual ~RModule()
	{
		_Instance() = nullptr;
		IsDestroyed() = true;
	}

	RModule(const RModule&)
	{

	}

	RModule& operator=(const RModule&)
	{
		return *this;
	}

protected:
	/************************************************************************************************************************/
	/**
	* @brief	Override if you want your module to be notified just before it is deleted.
	*
	* @note		Useful when your module is polymorphic and you might want to perform some kind of clean up perhaps overriding
	*			that of a base class.
	*/
	/************************************************************************************************************************/
	virtual void OnShutDown()
	{

	}
	virtual void OnStartUp(void* _Desc)
	{

	}

	/************************************************************************************************************************/
	/**
	* @brief	Returns a singleton instance of this module. Throws an exception if module is not yet initialized.
	*/
	/************************************************************************************************************************/
	static T*& _Instance()
	{
		static T* inst = nullptr;
		return inst;
	}

	/************************************************************************************************************************/
	/**
	* @brief	Checks has the Module been shut down.
	*
	* @note		If module was never even started, this will return false.
	*/
	/************************************************************************************************************************/
	static bool& IsDestroyed()
	{
		static bool inst = false;
		return inst;
	}

	/************************************************************************************************************************/
	/**
	* @brief	Checks has the Module been started up.
	*/
	/************************************************************************************************************************/
	static bool& IsShutDown()
	{
		static bool inst = true;
		return inst;
	}
};