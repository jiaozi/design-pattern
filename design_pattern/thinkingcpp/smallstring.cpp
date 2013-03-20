#include <string>
#include <iostream>
#include <cassert>

int main()
{
	std::string s1("What is the sound of one clam napping?");
	std::string s2("Anything worth doing is worth overdoing.");
	std::string s3("I saw Elyis in a UFO");
	std::string s4(s1, 0, 8);
	std::cout << s4 << std::endl;
	std::string s5(s2, 15, 6);
	std::cout << s5 << std::endl;
	std::string s6(s3, 6, 15);
	std::cout << s6 << std::endl;
	std::string quoteMe = s4 + "that" + s1.substr(20,10) + s5 + "with" + s3.substr(5, 100) + s1.substr(37,1);
	std::cout << quoteMe << std::endl;

	std::string source("xxx");
	std::string s(source.begin(), source.end());
	assert(s == source);
	return 0;
}