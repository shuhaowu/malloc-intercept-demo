#include "monitoring.h"

static thread_local bool g_monitoring_enabled = false;

void EnableMonitoring() { g_monitoring_enabled = true; }

void DisableMonitoring() { g_monitoring_enabled = false; }

bool MemoryMonitoringEnabled() { return g_monitoring_enabled; }
