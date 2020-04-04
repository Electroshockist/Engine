#include "Debug.h"
#include "../Utilities/FilePathParser.h"
#include <algorithm>

using namespace std;

string Debug::outputileName = "ME Engine.log";
MessageType Debug::currentSeverity = MessageType::TYPE_NONE;


void Debug::debugInit() {
	ofstream out;
	out.open(outputileName, ios::out);
	out.close();

	currentSeverity = MessageType::TYPE_FATAL_ERROR;
}

void Debug::debugInit(string & filename) {
	outputileName = filename;
	Debug::debugInit();
}

void Debug::setSeverity(MessageType type) {
	currentSeverity = type;
}

void Debug::info(const string & message, const string & filename, const int line) {
	Log(MessageType::TYPE_INFO, "Info: " + message, simplifyFileName(filename), line);
}

void Debug::trace(const string & message, const string & filename, const int line) {
	Log(MessageType::TYPE_INFO, "Trace: " + message, simplifyFileName(filename), line);
}

void Debug::warning(const string & message, const string & filename, const int line) {
	Log(MessageType::TYPE_INFO, "Warning: " + message, simplifyFileName(filename), line);
}

void Debug::error(const string & message, const string & filename, const int line) {
	Log(MessageType::TYPE_INFO, "Error: " + message, simplifyFileName(filename), line);
}

void Debug::fatalError(const string & message, const string & filename, const int line) {
	Log(MessageType::TYPE_INFO, "Fatal Error: " + message, simplifyFileName(filename), line);
}

void Debug::Log(const MessageType type, const string & message, const string & filename, const int line) {
	ofstream file;
	file.open(outputileName, ios::app | ios::out);
	if (type <= currentSeverity && currentSeverity > MessageType::TYPE_NONE) {
		std::cout << message << "\nin " << filename << " on line " << line << endl;
		file << message << "\nin " << filename << " on line " << line << endl;
	}
	file.flush();
	file.close();
}

string Debug::simplifyFileName(const string filename) {
	//cout << "Project path:" <<  projectPath << endl << "File path:" << filename << endl << "Subtracted path:" << filename.substr(projectPath.size()) << "\n\n";
	//truncate at position
	return filename.substr(FilePathParser::getProjectPath().size());
}
