int main()
{
	printf("%d\n", 1, 2, 3);
	printf("%d%d\n", 1);

	try
	{
		cpp_print("%d\n", 1, 2, 3);
		cpp_print("%d%d\n", 1);
	}
	catch (...)
	{
		std::cout << "예외 발생" << std::endl;
	}
}
