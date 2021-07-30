class random {

private:
	//Disables copying through assignment
	random(const random&) = delete;

	//Makes the constructor unavailable out of the class (no instanciation)
	random() {
	}

	//store a static instance of the singleton
	static random _instance;


	//Singleton private data
	float gen = 0.5F;

public:

	//Singleton operation on class members
	float r_float_impl() {
		return gen;
	}
	//So that we can call random::r_float directly
	static float r_float() {
		return get().r_float_impl();
	}

	//gets a reference to the static singleton instance
	static random& get() {
		static random instance;
		return instance;
	}
};