#pragma once

#include <optional>

namespace Utility {

template<typename Value, typename Error>
class Result {
public:
    Result(const Value& value):
        m_result(value) {}

    Result(Value&& value):
        m_result(std::move(value)) {}

    Result(const Error& error):
        m_error(error) {}

    Result(Error&& error):
        m_error(std::move(error)) {}

    Result(Result&& other) = default;
    Result(const Result& other) = default;
    ~Result() = default;

    Value& value()
    {
        return m_result.value();
    }

    Error& error()
    {
        return m_error.value();
    }

    bool is_error()
    {
        return m_error.has_value();
    }
    
private:
    std::optional<Value> m_result;
    std::optional<Error> m_error;
};

template<typename Error>
class Result<void, Error> {
public:
    Result(const Error& error):
        m_error(error) {}

    Result(Error&& error):
        m_error(std::move(error)) {}

    Result() = default;
    Result(Result&& other) = default;
    Result(const Result& other) = default;
    ~Result() = default;

    Error& error()
    {
        return m_error.value();
    }

    bool is_error() const
    {
        return m_error.has_value();
    }

private:
    std::optional<Error> m_error;
};

}
