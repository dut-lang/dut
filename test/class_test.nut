#!/usr/bin/env nut
/**
 * @ExpectResult("TestClass created\ntestMethod called")
 */



class TestClass
{
	constructor()
	{
		print("TestClass created\n")
	}

	function testMethod()
	{
		print("testMethod called\n")
	}
}

local test = TestClass()
test.testMethod()
