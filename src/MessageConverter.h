//Copyright 2018 Competence Center ISOBUS e.V.

//Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
//http://www.apache.org/licenses/LICENSE-2.0
//Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


#ifndef MESSAGECONVERTER_231683E1D9C847AC915E9491B4ECEB02
#define MESSAGECONVERTER_231683E1D9C847AC915E9491B4ECEB02

#include <QString>

namespace CCIAgrirouter
{

class SSLConnection;
struct Request;
struct Response;
struct ResponseMessage;

class MessageConverter
{
public:
    // Local encoding/decoding
    static QString encodeRequest(const Request &request);
    static QString encodeResponse(const Response &response);
    static Request decodeRequest(const QString &encoded);
    static Response decodeResponse(const QString &encoded);
    static QList<ResponseMessage> decodeResponseString(const QString &responseString);

private:
    MessageConverter(){}
};

}

#endif//MESSAGECONVERTER_231683E1D9C847AC915E9491B4ECEB02
