#pragma once
#include "MyTools.h"
class Bomb;
class Plane;

class Visitor {
public:
	virtual ~Visitor() = default;
	virtual void log(Bomb* b) = 0;
	virtual void log(Plane* p) = 0;
};

class LogVisitor : public Visitor {
public:
	LogVisitor(MyTools::ILogger& logger);
	void log(Bomb* b) override;
	void log(Plane* p) override;
private:
	MyTools::ILogger& logger;
};