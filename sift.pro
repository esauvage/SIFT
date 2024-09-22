TEMPLATE = subdirs
SUBDIRS = examples/find_keypoints.pro examples/match_features.pro src/sift.pro src/image.pro
match_features.depends = image sift
find_keypoints.depends = image sift
