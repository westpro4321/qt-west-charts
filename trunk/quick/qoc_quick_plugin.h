#ifndef QOC_QUICK_PLUGIN_H
#define QOC_QUICK_PLUGIN_H

#include <QQmlExtensionPlugin>

#include "qoc_quick_global.h"

class QOC_QUICK_API QocQuickPlugin : public QQmlExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-office-charts.Qt.QocQuickPlugin")
public:
	explicit QocQuickPlugin(QObject *parent = 0);

	void registerTypes(const char *uri);
	
signals:
	
public slots:
	
};

#endif // QOC_QUICK_PLUGIN_H
