#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Game : public QGraphicsView {
    Q_OBJECT

    public:
        Game(QWidget* parent = nullptr);
        ~Game();

    private:
        QGraphicsScene* scene;
        QGraphicsRectItem* rect;
};

Game::Game(QWidget* parent) : QGraphicsView(parent) {
    // Create the scene
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Create the rectangle
    rect = scene->addRect(0, 0, 50, 50);
    rect->setBrush(Qt::red);

    // Set the scene size
    setFixedSize(800, 600);

    // Start the animation
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        rect->moveBy(1, 1);
    });
    timer->start(1000 / 60);
}

Game::~Game() {
    delete scene;
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Game game;
    game.show();

    return app.exec();
}
