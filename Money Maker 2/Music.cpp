#include "Music.h"

Music::Music()
	:mRd(), mMt(mRd()), distribution(1, 14), mWhatFile(distribution(mMt))
{
	mSongs.emplace_back("Music/BLISSbyKENARAI.ogg");
	mSongs.emplace_back("Music/HamptontheHamsterTheHamsterdanceSong.ogg");
	mSongs.emplace_back("Music/LatinIndustries.ogg");
	mSongs.emplace_back("Music/MissMonomisPracticeLesson.ogg");
	mSongs.emplace_back("Music/MyDearestENGLISHver.ogg");
	mSongs.emplace_back("Music/NEXT TO YOUbyKENARAIParasyteTheMaximKiseijuuSeinoKakuritsuOST.ogg");
	mSongs.emplace_back("Music/PinballSpring.ogg");
	mSongs.emplace_back("Music/SunflowerDanceParty.ogg");
	mSongs.emplace_back("Music/ShowYourMoves.ogg");
	mSongs.emplace_back("Music/TheDuckSong.ogg");
	mSongs.emplace_back("Music/[Future Bass]-Subtact-Restart[Monstercat Release].ogg");
	mSongs.emplace_back("Music/TheFatRat-MAYDAYfeat.Laura Brehm.ogg");
	mSongs.emplace_back("Music/TheFatRat-Monody(feat.Laura Brehm).ogg");
	mSongs.emplace_back("Music/TheFatRat-FlyAwayfeat.Anjulie.ogg");
}

void Music::Play()
{
	mWhatFile = distribution(mMt);
	mWhatFile--;

	mMusic.openFromFile(mSongs.at(mWhatFile));

	mMusic.play();

}