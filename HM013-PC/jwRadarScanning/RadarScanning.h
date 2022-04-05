#ifndef RADARSCANNING_H
#define RADARSCANNING_H

#include <QWidget>

class RadarScanning : public QWidget
{
	Q_OBJECT

	struct PosStruct
	{
		QPoint pos;
		int animation;
	};

public:
	RadarScanning(QWidget *parent = nullptr);
protected:
	void paintEvent(QPaintEvent* e) override;
	void resizeEvent(QResizeEvent* e) override;

private:
	void drawBackground(QPainter&);
	void drawScanning(QPainter&);
	void drawScale(QPainter& pai);
	void drawLock(QPainter&, PosStruct&);

    int m_r = 10;
	QPixmap* bg;

	QTimer* animation_time = nullptr;
	int arc = 280;



	std::vector<PosStruct> *vec;

private slots:
	void timeOut();
};

#endif // !RADARSCANNING_H
