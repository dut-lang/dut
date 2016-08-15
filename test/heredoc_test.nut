#!/usr/bin/env nut
/**
 * @ExpectIgnore("Not implemented yet")
 * @ExpectResult <<--
 * Heredoc string first line
 * Heredoc string second line
 * -->>
 */

local var = <<-EOS
	Heredoc string first line
	Heredoc string second line
EOS

print(var + "\n")
