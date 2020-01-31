#include "AManager.h"

template <typename T>
std::unique_ptr<AManager<T>> AManager<T>::managerInstance = nullptr;