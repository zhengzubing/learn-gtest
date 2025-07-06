#include <gtest/gtest.h>

class BankAccount {
    public:
    BankAccount(unsigned int money = 0) : mMoney(money) {};
    ~BankAccount() {};
    unsigned int getMoney() const { return mMoney; }

    private:
    unsigned int mMoney = 0;
};

class BankAccountTest : public ::testing::Test {
    public:
    BankAccountTest() {
        std::cout << "BankAccountTest test" << std::endl;
        mAccount = new BankAccount();
    }
    ~BankAccountTest() {
        std::cout << "BankAccountTest ~test" << std::endl;
        delete mAccount;
    }

    void SetUp() override {
        std::cout << "BankAccountTest SetUp" << std::endl;
    }

    void TearDown() override {
        std::cout << "BankAccountTest TearDown" << std::endl;
    }

    BankAccount* mAccount;
};

TEST(TestDemo, EnvTest) {
    EXPECT_EQ(2, 1 + 1);
}

TEST_F(BankAccountTest, TestNameInit) {
    std::cout << "BankAccountTest TestNameInit" << std::endl;
    EXPECT_EQ(0, mAccount->getMoney());
}


int Add(int a, int b) {
    return a + b;
}

struct TestStruct {
    TestStruct(int a, int b, int ret) : a(a), b(b), ret(ret) {
        std::cout << "TestStruct TestStruct" << std::endl;
    }
    ~TestStruct() {
        std::cout << a << " " << b << " " << ret << std::endl;
        std::cout << "TestStruct ~testStruct" << std::endl;
    }
    int a;
    int b;
    int ret;
};

class AddParamTest : public ::testing::TestWithParam<TestStruct> {
    public:
    AddParamTest() {
        std::cout << "BankAccountTest AddParamTest" << std::endl;
    }
    ~AddParamTest() {
        std::cout << "BankAccountTest ~AddParamTest" << std::endl;
    }
};

INSTANTIATE_TEST_SUITE_P(
    AddTestCase, // tag
    AddParamTest,
    ::testing::Values(
        TestStruct{1, 2, 3},
        TestStruct{2, 2, 4}
    )
);

TEST_P(AddParamTest, CheckAddition) {
    const auto& param = GetParam();
    EXPECT_EQ(Add(param.a, param.b), param.ret);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}