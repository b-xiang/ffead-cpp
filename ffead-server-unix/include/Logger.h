/*
	Copyright 2010, Sumeet Chhetri 
  
    Licensed under the Apache License, Version 2.0 (the "License"); 
    you may not use this file except in compliance with the License. 
    You may obtain a copy of the License at 
  
        http://www.apache.org/licenses/LICENSE-2.0 
  
    Unless required by applicable law or agreed to in writing, software 
    distributed under the License is distributed on an "AS IS" BASIS, 
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
    See the License for the specific language governing permissions and 
    limitations under the License.  
*/
/*
 * Logger.h
 *
 *  Created on: Sep 5, 2009
 *      Author: sumeet
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "PropFileReader.h"
#include "DateFormat.h"
#include <boost/thread/thread.hpp>
class Logger {
public:
	static Logger* getLogger();
	static void info(string);
	static void debug(string);
	static void error(string);
	static void init();
	static void init(string file);
	static void init(string level,string mode,string file);
private:
	virtual ~Logger();
	Logger();
	Logger(string);
	Logger(string,string,string);
	DateFormat datFormat;
	string level;
	string mode;
	string filepath;
	ofstream out;
	void write(string,string);
	boost::mutex p_mutex;
	static Logger* m_pInstance;
};

#endif /* LOGGER_H_ */