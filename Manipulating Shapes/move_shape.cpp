# include <Siv3D.hpp> // Siv3D v0.6.16
void move_shape() {
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Rect rect{ 100, 100, 300 };

	Circle circle{ 600, 100, 100 };

	while (System::Update())
	{
		circle.moveBy(0, (Scene::DeltaTime() * 100.0));

		rect.draw();

		rect.movedBy(40, 40).draw(Palette::Seagreen);

		circle.draw(ColorF{ 0.2 });
	}
}
