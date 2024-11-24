#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 120;
	for (int x = span * 1; x <= ofGetWindowWidth() - span * 1; x += span) {

		for (int y = span * 1; y <= ofGetWindowHeight() - span * 1; y += span) {

			auto seed = ofRandom(1000);
			vector<glm::vec2> vertices;

			for (int i = 0; i < 60; i++) {

				auto center = glm::vec2(x, y);
				auto radius = 80;

				for (int draw_radius = radius; draw_radius > 0;) {

					auto tmp_radius = draw_radius;
					draw_radius -= 10;

					auto deg = ofMap(ofNoise(seed, draw_radius, (ofGetFrameNum() + i) * 0.005), 0, 1, -360 * 3 , 360 * 3);
					auto center_radius = tmp_radius - draw_radius;
					center = center + glm::vec2(center_radius * cos(deg * DEG_TO_RAD), center_radius * sin(deg * DEG_TO_RAD));

					if (draw_radius == 10) {

						vertices.push_back(center);
					}
				}

				for (int i = 1; i < vertices.size(); i++) {

					ofSetColor(ofMap(i, 1, vertices.size(), 239, 0));
					ofDrawLine(vertices[i - 1], vertices[i]);
				}
			}
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}