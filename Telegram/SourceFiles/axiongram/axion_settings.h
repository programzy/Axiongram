#pragma once

#include "settings.h"
#include <QtCore/QSettings>
#include <QtCore/QString>
#include <QtCore/QDir>

namespace Axiongram {

class Settings final {
private:
	static QString ConfigPath() {
		const auto dir = cWorkingDir();
		if (!dir.isEmpty()) {
			return dir + u"tdata/axion_settings.ini"_q;
		}
		return u"tdata/axion_settings.ini"_q;
	}

	static QSettings Config() {
		return QSettings(ConfigPath(), QSettings::IniFormat);
	}

public:
	// Ghost Mode
	static bool GhostMode() {
		return Config().value(u"ghost_mode"_q, false).toBool();
	}
	static void SetGhostMode(bool enabled) {
		auto c = Config();
		c.setValue(u"ghost_mode"_q, enabled);
		c.sync();
	}

	// Hide typing
	static bool HideTyping() {
		return Config().value(u"hide_typing"_q, false).toBool();
	}
	static void SetHideTyping(bool enabled) {
		auto c = Config();
		c.setValue(u"hide_typing"_q, enabled);
		c.sync();
	}

	// Hide read voice & video notes
	static bool HideReadVoice() {
		return Config().value(u"hide_read_voice"_q, false).toBool();
	}
	static void SetHideReadVoice(bool enabled) {
		auto c = Config();
		c.setValue(u"hide_read_voice"_q, enabled);
		c.sync();
	}

	// Offline mode
	static bool OfflineMode() {
		return Config().value(u"offline_mode"_q, false).toBool();
	}
	static void SetOfflineMode(bool enabled) {
		auto c = Config();
		c.setValue(u"offline_mode"_q, enabled);
		c.sync();
	}

	// Anti-delete
	static bool AntiDelete() {
		return Config().value(u"anti_delete"_q, true).toBool();
	}
	static void SetAntiDelete(bool enabled) {
		auto c = Config();
		c.setValue(u"anti_delete"_q, enabled);
		c.sync();
	}

	// Anti-edit
	static bool AntiEdit() {
		return Config().value(u"anti_edit"_q, true).toBool();
	}
	static void SetAntiEdit(bool enabled) {
		auto c = Config();
		c.setValue(u"anti_edit"_q, enabled);
		c.sync();
	}

	// Save restricted content
	static bool AllowSaveRestricted() {
		return Config().value(u"save_restricted"_q, true).toBool();
	}
	static void SetAllowSaveRestricted(bool enabled) {
		auto c = Config();
		c.setValue(u"save_restricted"_q, enabled);
		c.sync();
	}

	// Prevent TTL media self-destruct
	static bool PreventTTL() {
		return Config().value(u"prevent_ttl"_q, true).toBool();
	}
	static void SetPreventTTL(bool enabled) {
		auto c = Config();
		c.setValue(u"prevent_ttl"_q, enabled);
		c.sync();
	}

	// Drop forward author
	static bool DropForwardAuthor() {
		return Config().value(u"drop_forward_author"_q, false).toBool();
	}
	static void SetDropForwardAuthor(bool enabled) {
		auto c = Config();
		c.setValue(u"drop_forward_author"_q, enabled);
		c.sync();
	}

	// Block sponsored messages
	static bool BlockSponsored() {
		return Config().value(u"block_sponsored"_q, true).toBool();
	}
	static void SetBlockSponsored(bool enabled) {
		auto c = Config();
		c.setValue(u"block_sponsored"_q, enabled);
		c.sync();
	}

	// Show numeric ID
	static bool ShowPeerId() {
		return Config().value(u"show_peer_id"_q, true).toBool();
	}
	static void SetShowPeerId(bool enabled) {
		auto c = Config();
		c.setValue(u"show_peer_id"_q, enabled);
		c.sync();
	}

	// Creator check
	static bool IsCreator(const QString &username) {
		return (username.compare(u"goodbye_death"_q, Qt::CaseInsensitive) == 0);
	}

	// Custom badge
	static QString GetCustomBadge(const QString &username) {
		if (username.isEmpty()) return QString();
		return Config().value(u"badges/"_q + username.toLower(), QString()).toString();
	}
};

} // namespace Axiongram
