#include "gui.h"



using namespace nana;

GUI::GUI() {

}

void GUI::run(int animalsRatio, int plantsRatio, int mapSize) {
    Map map(mapSize,animalsRatio,plantsRatio);
    Evolution ev(&map);
    Simulation sim(&ev);
    sim.run();
}

void GUI::drawInterface() {
    form fm;
    fm.caption("Simulation interface");

    label lbl1(fm);
    lbl1.caption("Map size");
    lbl1.text_align(align::left, align_v::center);
    label lbl2(fm);
    lbl2.caption("Animals reproducing");
    lbl2.text_align(align::left, align_v::center);
    label lbl3(fm);
    lbl3.caption("Plants growing");
    lbl3.text_align(align::left, align_v::center);

    slider slider2(fm);
    slider2.maximum(10);
    slider2.value(5);
    slider2.transparent(false);

    slider slider3(fm);
    slider3.maximum(10);
    slider3.value(5);
    slider3.transparent(false);

    textbox textbox1(fm);
    textbox textbox2(fm);
    textbox textbox3(fm);

    button btn(fm);
    btn.caption("Start!");
    btn.events().click([&textbox1, &slider2, &slider3, this, &fm, &btn]{
        int temp;
        if (textbox1.text().empty()) temp =10;
        else temp=std::stoi(textbox1.text());
        btn.enabled(false);
        GUI::run(slider2.value(), slider3.value(), temp);
        btn.enabled(true);

    });

    place layout(fm);
    layout.div("<margin=[15%,10%] vertical <first><><second><><third><><weight=25 buttons>>");
    layout.field("first") << lbl1<< textbox1;
    layout.field("second") << lbl2<< slider2;
    layout.field("third") << lbl3<< slider3;
    layout.field("buttons") << btn;
    layout.collocate();
    fm.show();
    exec();


}

GUI::~GUI() {

}
