#include "Protocol.h"
#include "SerialDevice.h"
#include "CommunicationDevice.h"
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include "gmock/gmock.h"

class ProtocolMock : public Protocol {
public:
    ProtocolMock() : Protocol() {};
    MOCK_METHOD1(sendData, void(std::string data));
};

class SerialDeviceMock : public SerialDevice {
public:
    SerialDeviceMock(Protocol* protocol) : SerialDevice(protocol) {};
    MOCK_METHOD0(turnOnEngine, void());
};

class CommunicationDeviceMock : public CommunicationDevice {
public:
    CommunicationDeviceMock(Protocol* protocol) : CommunicationDevice(protocol) {};
    MOCK_METHOD0(turnOnEngine, void());
};

TEST(Protocol, SendData) {
    ProtocolMock pr;
    EXPECT_CALL(pr, sendData(testing::_)).Times(1);
    pr.sendData("data");
}

TEST(SerialDevice, Init) {
    Protocol* pr;
    SerialDeviceMock sr(pr);
    EXPECT_CALL(sr, turnOnEngine()).Times(1);
    sr.turnOnEngine();
}

TEST(CommunicationDevice, Init) {
    Protocol* pr;
    CommunicationDeviceMock cm(pr);
    EXPECT_CALL(cm, turnOnEngine()).Times(1);
    cm.turnOnEngine();
}

