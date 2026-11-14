#pragma once

#include <QtCore/QSettings>
#include <QtCore/QString>

namespace Axiongram {

class Settings final {
public:
	static bool GhostMode() {
		return QSettings().value(u"axiongram/ghost_mode"_q, true).toBool();
	}
	static void SetGhostMode(bool enabled) {
		QSettings().setValue(u"axiongram/ghost_mode"_q, enabled);
	}

	static bool AntiDelete() {
		return QSettings().value(u"axiongram/anti_delete"_q, true).toBool();
	}
	static void SetAntiDelete(bool enabled) {
		QSettings().setValue(u"axiongram/anti_delete"_q, enabled);
	}
};

} // namespace Axiongram
