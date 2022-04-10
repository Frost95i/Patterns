
#include "Visitor.h"
#include <string>
#include "Bomb.h"
#include "Plane.h"



LogVisitor::LogVisitor(MyTools::ILogger& loggers) : logger(loggers) {}

void LogVisitor::log(Bomb* b)  {
	logger.WriteToLog("BOMB: Speed is " + std::to_string(b->GetSpeed()) + " " + "Direction is " + std::to_string(b->GetDirection()));
}

void LogVisitor::log(Plane* p) {
	logger.WriteToLog("PLANE: Speed is " + std::to_string(p->GetSpeed()) + " " + "Direction is " + std::to_string(p->GetDirection()));
}


