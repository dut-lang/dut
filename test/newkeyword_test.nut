#!/usr/bin/env nut
/**
 * @ExpectIgnore("New keyword is not implemented yet")
 * @ExpectResult("TestClass created")
 */

 class TestClass
 {
 	constructor()
 	{
 		print("TestClass created\n")
 	}
}

local test = new TestClass()
