//
// Created by vanya on 01.12.23.
//
#include "gtest/gtest.h"
#include "../include/config.h"
#include <exception>

class ConfigTest : public testing::Test {
protected:
    void SetUp() override {
        Config::deleteInstance();
    }
};

TEST_F(ConfigTest, InvalidConfig) {
    Config::setFilename("test/file/fail-cfg.json");
    ASSERT_THROW(Config::getInstance(), std::runtime_error);
}

TEST_F(ConfigTest, ValidConfig) {
    Config::setFilename("test/file/ok-cfg.json");
    EXPECT_NO_THROW(Config::getInstance());

    EXPECT_EQ(Config::getInstance()->getQuerySize(), 1);
    EXPECT_EQ(Config::getInstance()->getOperatorsCount(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMin(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMax(), 1);
    EXPECT_EQ(Config::getInstance()->getMinQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getMaxQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getJournalFilename(), "1");

}

using namespace std::chrono_literals;

TEST_F(ConfigTest, ValidUpdateConfig) {
    Config::setFilename("test/file/ok-cfg.json");
    EXPECT_NO_THROW(Config::getInstance());

    EXPECT_EQ(Config::getInstance()->getQuerySize(), 1);
    EXPECT_EQ(Config::getInstance()->getOperatorsCount(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMin(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMax(), 1);
    EXPECT_EQ(Config::getInstance()->getMinQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getMaxQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getJournalFilename(), "1");

    Config::setFilename("test/file/upd-cfg.json");
    std::thread configUpdater(Config::updateConfig);

    std::this_thread::sleep_for(1s);

    EXPECT_EQ(Config::getInstance()->getQuerySize(), 5);
    EXPECT_EQ(Config::getInstance()->getOperatorsCount(), 5);
    EXPECT_EQ(Config::getInstance()->getResponseMin(), 5);
    EXPECT_EQ(Config::getInstance()->getResponseMax(), 5);
    EXPECT_EQ(Config::getInstance()->getMinQueueExpirationTime(), 5);
    EXPECT_EQ(Config::getInstance()->getMaxQueueExpirationTime(), 5);
    EXPECT_EQ(Config::getInstance()->getJournalFilename(), "5");

    configUpdater.detach();
}

TEST_F(ConfigTest, InvalidUpdateConfig) {

    Config::setFilename("test/file/ok-cfg.json");
    EXPECT_NO_THROW(Config::getInstance());

    EXPECT_EQ(Config::getInstance()->getQuerySize(), 1);
    EXPECT_EQ(Config::getInstance()->getOperatorsCount(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMin(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMax(), 1);
    EXPECT_EQ(Config::getInstance()->getMinQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getMaxQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getJournalFilename(), "1");

    Config::setFilename("test/file/upd-fail-cfg.json");
    std::thread configUpdater(Config::updateConfig);

    std::this_thread::sleep_for(1s);

    EXPECT_EQ(Config::getInstance()->getQuerySize(), 1);
    EXPECT_EQ(Config::getInstance()->getOperatorsCount(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMin(), 1);
    EXPECT_EQ(Config::getInstance()->getResponseMax(), 1);
    EXPECT_EQ(Config::getInstance()->getMinQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getMaxQueueExpirationTime(), 1);
    EXPECT_EQ(Config::getInstance()->getJournalFilename(), "1");

    configUpdater.detach();
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}