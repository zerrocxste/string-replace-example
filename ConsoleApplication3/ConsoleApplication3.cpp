#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

void string_replace(char* dest, const char* find, const char* replace)
{
	char save_dest[1024] = { NULL };
	strcpy(save_dest, dest);

	auto replace_length = strlen(replace);
	auto find_length = strlen(find);

	for (int i = 0; i < strlen(dest); i++)
	{
		auto founded = strstr(dest, find);

		if (founded == NULL)
			continue;

		if (strcmp(dest + i, founded) != NULL)
			continue;

		memmove(dest + i, replace, strlen(dest) + replace_length);
		memcpy(dest + strlen(dest), save_dest + i + find_length, strlen(save_dest) + i + find_length);
		strcpy(save_dest, dest);
	}
}

int main()
{
	char my_str[1024] = "stroki v c kruta!!!!!!!!! 123";

	string_replace(my_str, "kruta!!!!!!!!!", "xuinya...");

	std::cout << my_str << std::endl;
}
