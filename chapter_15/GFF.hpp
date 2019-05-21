#include <string>

using namespace std;

class GFF{
	public:
		virtual void usedAlgorithm();
	protected:
	
	private:
		string name;
};

class GIF:public GFF{
	
	
};

class TIFF:public GFF{
	
};

class JPEG:public GFF{
	
};

class BMP:public GFF{
	
};

