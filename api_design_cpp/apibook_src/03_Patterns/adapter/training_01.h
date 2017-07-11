class Original;

class Adapter
{
public:
	Adapter();
	~Adapter();

	bool Dosomething(int value);
private:
	Adapter(const Adapter &);
	const Adapter &operator =(const Adapter &);

	Original *mOrig;
};
