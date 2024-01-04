class Singleton {
private:
	static Singleton* loggerInstance;
	static int i;
	static mutex mtx;
	Singleton() {
		i++;
	}

public:
	static Singleton* getlogger() {
		if (loggerInstance == nullptr) {
			mtx.lock();
			if (loggerInstance == nullptr) {
				loggerInstance = new Singleton();
			}
			mtx.unlock();
		}
		return loggerInstance;
		
	}

	void log(string msg) {
		cout << msg <<" "<<i<< endl;
	}
};

Singleton* Singleton::loggerInstance = nullptr;
int Singleton::i = 0;
mutex Singleton::mtx;


void user1() {
	Singleton* obj1 = Singleton::getlogger();
	obj1->log("Msg from user 1");
}


void user2() {
	Singleton* obj2 = Singleton::getlogger();
	obj2->log("Msg from user 2");
}

int main() {


	thread t1(user1);
	thread t2(user2);

	t1.join();
	t2.join();
