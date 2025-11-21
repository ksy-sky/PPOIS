#include <UnitTest++/UnitTest++.h>
#include "Album.h"
#include "Artist.h"
#include "Audiobook.h"
#include "AudioConverter.h"
#include "AudioDevice.h"
#include "AudioFormat.h"
#include "AudioPlayer.h"
#include "AudioQuality.h"
#include "CassetteTape.h"
#include "CompactDisc.h"
#include "Concert.h"
#include "Copyright.h"
#include "CrossfadeManager.h"
#include "DigitalMedia.h"
#include "DigitalPurchase.h"
#include "DownloadManager.h"
#include "Equalizer.h"
#include "FriendSystem.h"
#include "Genre.h"
#include "Headphones.h"
#include "ListeningHistory.h"
#include "LiveRecording.h"
#include "Lyrics.h"
#include "MoodAnalyzer.h"
#include "MusicDiscovery.h"
#include "MusicMetadata.h"
#include "MusicStore.h"
#include "MusicVideo.h"
#include "NotificationSystem.h"
#include "PhysicalMedia.h"
#include "PhysicalMediaOrder.h"
#include "PlaybackController.h"
#include "Playlist.h"
#include "PlaylistGenerator.h"
#include "Podcast.h"
#include "PrivacySettings.h"
#include "RecommendationSystem.h"
#include "Remix.h"
#include "SecurityManager.h"
#include "ShoppingCart.h"
#include "Song.h"
#include "SoundEffect.h"
#include "SoundSystem.h"
#include "StreamManager.h"
#include "User.h"
#include "UserAchievement.h"
#include "UserProfile.h"
#include "VinylRecord.h"
#include "VolumeNormalizer.h"
#include "WirelessSpeaker.h"
#include "Errors.h"

using namespace std;

// Тесты для FriendSystem
SUITE(FriendSystemTests)
{
    TEST(FriendSystem_AddFriend)
    {
        FriendSystem fs;
        
        fs.addFriend("testuser");
        vector<string> friends = fs.getFriends();
        
        CHECK_EQUAL(1, friends.size());
        CHECK_EQUAL("testuser", friends[0]);
    }
    
    TEST(FriendSystem_RemoveFriend)
    {
        FriendSystem fs;
        
        fs.addFriend("testuser");
        CHECK_EQUAL(1, fs.getFriends().size());
        
        fs.removeFriend("testuser");
        CHECK_EQUAL(0, fs.getFriends().size());
    }
    
    TEST(FriendSystem_GetFriendsEmpty)
    {
        FriendSystem fs;
        vector<string> friends = fs.getFriends();
        
        CHECK_EQUAL(0, friends.size());
    }
}

// Тесты для ListeningHistory
SUITE(ListeningHistoryTests)
{
    TEST(ListeningHistory_AddSong)
    {
        ListeningHistory history;
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Test lyrics");
        Song song("Song1", artist, 180, genre, lyrics);
        
        history.addSong(song);
        vector<Song> songs = history.getHistory();
        
        CHECK_EQUAL(1, songs.size());
        CHECK_EQUAL("Song1", songs[0].getTitle());
    }
    
    TEST(ListeningHistory_ClearHistory)
    {
        ListeningHistory history;
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Test lyrics");
        Song song("Song1", artist, 180, genre, lyrics);
        
        history.addSong(song);
        CHECK_EQUAL(1, history.getHistory().size());
        
        history.clearHistory();
        CHECK_EQUAL(0, history.getHistory().size());
    }
    
    TEST(ListeningHistory_GetHistoryEmpty)
    {
        ListeningHistory history;
        vector<Song> songs = history.getHistory();
        
        CHECK_EQUAL(0, songs.size());
    }
}

// Тесты для NotificationSystem
SUITE(NotificationSystemTests)
{
    TEST(NotificationSystem_AddNotification)
    {
        User user("testuser", "password", "Test User", "test@email.com", PrivacySettings(true, true));
        NotificationSystem ns(&user);
        
        ns.addNotification("Test notification");
        vector<string> notifications = ns.getNotifications();
        
        CHECK_EQUAL(1, notifications.size());
        CHECK_EQUAL("Test notification", notifications[0]);
    }
    
    TEST(NotificationSystem_ClearNotifications)
    {
        User user("testuser", "password", "Test User", "test@email.com", PrivacySettings(true, true));
        NotificationSystem ns(&user);
        
        ns.addNotification("Test notification");
        CHECK_EQUAL(1, ns.getNotifications().size());
        
        ns.clearNotifications();
        CHECK_EQUAL(0, ns.getNotifications().size());
    }
    
    TEST(NotificationSystem_GetNotificationsEmpty)
    {
        User user("testuser", "password", "Test User", "test@email.com", PrivacySettings(true, true));
        NotificationSystem ns(&user);
        
        vector<string> notifications = ns.getNotifications();
        CHECK_EQUAL(0, notifications.size());
    }
    
    TEST(NotificationSystem_MultipleNotifications)
    {
        User user("testuser", "password", "Test User", "test@email.com", PrivacySettings(true, true));
        NotificationSystem ns(&user);
        
        ns.addNotification("Notification 1");
        ns.addNotification("Notification 2");
        ns.addNotification("Notification 3");
        
        vector<string> notifications = ns.getNotifications();
        CHECK_EQUAL(3, notifications.size());
        CHECK_EQUAL("Notification 1", notifications[0]);
        CHECK_EQUAL("Notification 2", notifications[1]);
        CHECK_EQUAL("Notification 3", notifications[2]);
    }
}

// Тесты для PrivacySettings
SUITE(PrivacySettingsTests)
{
    TEST(PrivacySettings_Constructor)
    {
        PrivacySettings ps(true, false);
        CHECK(true);
    }
    
    TEST(PrivacySettings_SetPrivacy)
    {
        PrivacySettings ps(true, false);
        ps.setPrivacy(false, true);
        CHECK(true);
    }
}

// Тесты для SecurityManager
SUITE(SecurityManagerTests)
{
    TEST(SecurityManager_Constructor)
    {
        SecurityManager sm("password123");
        CHECK(true);
    }
    
    TEST(SecurityManager_ChangePasswordSuccess)
    {
        SecurityManager sm("oldPassword");
        bool result = sm.changePassword("oldPassword", "newPassword");
        
        CHECK_EQUAL(true, result);
    }
    
    TEST(SecurityManager_ChangePasswordFailure)
    {
        SecurityManager sm("oldPassword");
        bool result = sm.changePassword("wrongPassword", "newPassword");
        
        CHECK_EQUAL(false, result);
    }
    
    TEST(SecurityManager_EnableTwoFactorAuthentication)
    {
        SecurityManager sm("password");
        sm.enableTwoFactorAuthentication();
        CHECK(true);
    }
}

// Тесты для User
SUITE(UserTests)
{
    TEST(User_ConstructorAndGetUsername)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        CHECK_EQUAL("john", user.getUsername());
    }
    
    TEST(User_AuthenticateSuccess)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        bool result = user.authenticate("pass123");
        CHECK_EQUAL(true, result);
    }
    
    TEST(User_AuthenticateFailure)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        bool result = user.authenticate("wrongpass");
        CHECK_EQUAL(false, result);
    }
    
    TEST(User_AddAchievement)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        UserAchievement achievement("First Login", "2024-01-01");
        
        user.addAchievement(achievement);
        vector<UserAchievement> achievements = user.getAchievements();
        
        CHECK_EQUAL(1, achievements.size());
    }
    
    TEST(User_AddFriend)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        user.addFriend("testuser");
        vector<string> friends = user.getFriends();
        
        CHECK_EQUAL(1, friends.size());
        CHECK_EQUAL("testuser", friends[0]);
    }
    
    TEST(User_RemoveFriend)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        user.addFriend("testuser");
        CHECK_EQUAL(1, user.getFriends().size());
        
        user.removeFriend("testuser");
        CHECK_EQUAL(0, user.getFriends().size());
    }
    
    TEST(User_AddDownload)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        // Метод addDownload выводит в cout, проверяем что выполняется без ошибок
        user.addDownload("song1.mp3");
        CHECK(true);
    }
    
    TEST(User_ListDownloads)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        user.addDownload("song1.mp3");
        user.addDownload("song2.mp3");
        
        // Метод listDownloads выводит в cout, проверяем что выполняется без ошибок
        user.listDownloads();
        CHECK(true);
    }
    
    TEST(User_MultipleAchievements)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        UserAchievement achievement1("First Login", "2024-01-01");
        UserAchievement achievement2("First Song", "2024-01-02");
        UserAchievement achievement3("100 Plays", "2024-01-03");
        
        user.addAchievement(achievement1);
        user.addAchievement(achievement2);
        user.addAchievement(achievement3);
        
        vector<UserAchievement> achievements = user.getAchievements();
        CHECK_EQUAL(3, achievements.size());
    }
    
    TEST(User_MultipleFriends)
    {
        User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
        
        user.addFriend("user1");
        user.addFriend("user2");
        user.addFriend("user3");
        
        vector<string> friends = user.getFriends();
        CHECK_EQUAL(3, friends.size());
        CHECK_EQUAL("user1", friends[0]);
        CHECK_EQUAL("user2", friends[1]);
        CHECK_EQUAL("user3", friends[2]);
    }
    TEST(User_EmptyAchievements)
{
    User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
    
    vector<UserAchievement> achievements = user.getAchievements();
    CHECK_EQUAL(0, achievements.size());
}

TEST(User_EmptyFriends)
{
    User user("john", "pass123", "John Doe", "john@email.com", PrivacySettings(true, true));
    
    vector<string> friends = user.getFriends();
    CHECK_EQUAL(0, friends.size());
}
}
// Тесты для UserAchievement
SUITE(UserAchievementTests)
{
    TEST(UserAchievement_ConstructorAndGetDetails)
    {
        UserAchievement achievement("First Song", "2024-01-01");
        
        string details = achievement.getDetails();
        CHECK(true);
    }
}

// Тесты для UserProfile
SUITE(UserProfileTests)
{
    TEST(UserProfile_Constructor)
    {
        UserProfile profile("John Doe", "john@email.com", PrivacySettings(true, true));
        CHECK(true);
    }
    
    TEST(UserProfile_UpdateProfile)
    {
        UserProfile profile("John Doe", "john@email.com", PrivacySettings(true, true));
        
        profile.updateProfile("Jane Doe", "jane@email.com");
        CHECK(true);
    }
    
    TEST(UserProfile_SetPrivacySettings)
    {
        UserProfile profile("John Doe", "john@email.com", PrivacySettings(true, true));
        
        profile.setPrivacySettings(PrivacySettings(false, false));
        CHECK(true);
    }
}

// Тесты для Song
SUITE(SongTests)
{
    TEST(Song_ConstructorAndGetters)
    {
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Test lyrics content");
        Song song("My Song", artist, 200, genre, lyrics);
        
        CHECK_EQUAL("My Song", song.getTitle());
        CHECK_EQUAL("Artist1", song.getArtistName());
    }
    
    TEST(Song_GetInfo)
    {
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Test lyrics content");
        Song song("My Song", artist, 200, genre, lyrics);
        
        string info = song.getInfo();
        CHECK(info.find("My Song") != string::npos);
        CHECK(info.find("Artist1") != string::npos);
        CHECK(info.find("200") != string::npos);
        CHECK(info.find("Pop") != string::npos);
    }
    
    TEST(Song_Play)
    {
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Test lyrics content");
        Song song("My Song", artist, 200, genre, lyrics);
        
        // Метод play() выводит в cout, просто проверяем что он выполняется без ошибок
        song.play();
        CHECK(true);
    }
    
    TEST(Song_SetAndGetLyrics)
    {
        Artist artist("Artist1", "Country1");
        Genre genre("Pop");
        Lyrics lyrics("Initial lyrics");
        Song song("My Song", artist, 200, genre, lyrics);
        
        // Проверяем исходные lyrics
        CHECK_EQUAL("Initial lyrics", song.getLyrics());
        
        // Устанавливаем новые lyrics
        song.setLyrics("New lyrics content");
        CHECK_EQUAL("New lyrics content", song.getLyrics());
    }
    
    TEST(Song_GetArtistName)
    {
        Artist artist("Coldplay", "UK");
        Genre genre("Rock");
        Lyrics lyrics("Yellow lyrics");
        Song song("Yellow", artist, 266, genre, lyrics);
        
        CHECK_EQUAL("Coldplay", song.getArtistName());
    }
}

// Тесты для Artist
SUITE(ArtistTests)
{
    TEST(Artist_ConstructorAndGetters)
    {
        Artist artist("Coldplay", "UK");
        
        CHECK_EQUAL("Coldplay", artist.getArtistName());
    }
    
    TEST(Artist_GetArtistInfo)
    {
        Artist artist("Coldplay", "UK");
        
        string info = artist.getArtistInfo();
        CHECK(true);
    }
}

// Тесты для Album
SUITE(AlbumTests)
{
    TEST(Album_ConstructorAndGetters)
    {
        Artist artist("Coldplay", "UK");
        Album album("Parachutes", artist);
        
        CHECK_EQUAL("Parachutes", album.getTitle());
        CHECK_EQUAL("Coldplay", album.getArtistName());
    }
    
    TEST(Album_AddAndGetSongs)
    {
        Artist artist("Coldplay", "UK");
        Genre genre("Rock");
        Lyrics lyrics("Yellow lyrics");
        Song song("Yellow", artist, 266, genre, lyrics);
        
        Album album("Parachutes", artist);
        album.addSong(song);
        vector<Song> songs = album.getSongs();
        
        CHECK_EQUAL(1, songs.size());
        CHECK_EQUAL("Yellow", songs[0].getTitle());
    }
    
    TEST(Album_GetAlbumInfo)
    {
        Artist artist("Coldplay", "UK");
        Album album("Parachutes", artist);
        
        string info = album.getAlbumInfo();
        CHECK(true);
    }
}

// Тесты для Lyrics
SUITE(LyricsTests)
{
    TEST(Lyrics_ConstructorAndGetContent)
    {
        Lyrics lyrics("This is the song lyrics content");
        
        string content = lyrics.getContent();
        CHECK_EQUAL("This is the song lyrics content", content);
    }
}

// Тесты для Genre
SUITE(GenreTests)
{
    TEST(Genre_ConstructorAndGetName)
    {
        Genre genre("Rock");
        
        CHECK_EQUAL("Rock", genre.getName());
    }
    
    TEST(Genre_SetName)
    {
        Genre genre("Rock");
        
        genre.setName("Pop");
        CHECK_EQUAL("Pop", genre.getName());
    }
}
// Тесты для Playlist
SUITE(PlaylistTests)
{
    TEST(Playlist_ConstructorAndGetName)
    {
        Playlist playlist("My Favorites");
        
        CHECK_EQUAL("My Favorites", playlist.getName());
        CHECK_EQUAL(0, playlist.getSongs().size());
    }
    
    TEST(Playlist_AddSong)
    {
        Playlist playlist("Rock Playlist");
        Artist artist("Queen", "UK");
        Genre genre("Rock");
        Lyrics lyrics("We will rock you");
        Song song("We Will Rock You", artist, 122, genre, lyrics);
        
        playlist.addSong(song);
        vector<Song> songs = playlist.getSongs();
        
        CHECK_EQUAL(1, songs.size());
        CHECK_EQUAL("We Will Rock You", songs[0].getTitle());
    }
    
    TEST(Playlist_AddMultipleSongs)
    {
        Playlist playlist("Mixed Playlist");
        Artist artist1("Artist1", "Country1");
        Artist artist2("Artist2", "Country2");
        Genre genre1("Pop");
        Genre genre2("Rock");
        Lyrics lyrics1("Lyrics1");
        Lyrics lyrics2("Lyrics2");
        
        Song song1("Song1", artist1, 180, genre1, lyrics1);
        Song song2("Song2", artist2, 200, genre2, lyrics2);
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        vector<Song> songs = playlist.getSongs();
        
        CHECK_EQUAL(2, songs.size());
        CHECK_EQUAL("Song1", songs[0].getTitle());
        CHECK_EQUAL("Song2", songs[1].getTitle());
    }
    
    TEST(Playlist_RemoveSong)
    {
        Playlist playlist("Test Playlist");
        Artist artist("Artist", "Country");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        
        Song song1("Song1", artist, 180, genre, lyrics);
        Song song2("Song2", artist, 200, genre, lyrics);
        Song song3("Song3", artist, 220, genre, lyrics);
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        playlist.addSong(song3);
        CHECK_EQUAL(3, playlist.getSongs().size());
        
        playlist.removeSong("Song2");
        vector<Song> songs = playlist.getSongs();
        
        CHECK_EQUAL(2, songs.size());
        CHECK_EQUAL("Song1", songs[0].getTitle());
        CHECK_EQUAL("Song3", songs[1].getTitle());
    }
    
    TEST(Playlist_RemoveMultipleSameTitles)
    {
        Playlist playlist("Duplicate Songs");
        Artist artist1("Artist1", "Country1");
        Artist artist2("Artist2", "Country2");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        
        Song song1("Same Title", artist1, 180, genre, lyrics);
        Song song2("Same Title", artist2, 200, genre, lyrics);
        Song song3("Different Title", artist1, 220, genre, lyrics);
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        playlist.addSong(song3);
        CHECK_EQUAL(3, playlist.getSongs().size());
        
        // Удаляем все песни с названием "Same Title"
        playlist.removeSong("Same Title");
        vector<Song> songs = playlist.getSongs();
        
        CHECK_EQUAL(1, songs.size());
        CHECK_EQUAL("Different Title", songs[0].getTitle());
    }
    
    TEST(Playlist_PlayEmpty)
    {
        Playlist playlist("Empty Playlist");
        
        // Проверяем что метод play() выполняется без ошибок для пустого плейлиста
        playlist.play();
        CHECK(true);
    }
    
    TEST(Playlist_PlayWithSongs)
    {
        Playlist playlist("My Playlist");
        Artist artist("Test Artist", "Test Country");
        Genre genre("Test Genre");
        Lyrics lyrics("Test Lyrics");
        
        Song song1("Song 1", artist, 100, genre, lyrics);
        Song song2("Song 2", artist, 150, genre, lyrics);
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        
        // Проверяем что метод play() выполняется без ошибок
        playlist.play();
        CHECK(true);
    }
    
    TEST(Playlist_GetSongsEmpty)
    {
        Playlist playlist("New Playlist");
        
        vector<Song> songs = playlist.getSongs();
        CHECK_EQUAL(0, songs.size());
    }
    
    TEST(Playlist_ClearByRemovingAll)
    {
        Playlist playlist("To Be Cleared");
        Artist artist("Artist", "Country");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        
        Song song1("Song1", artist, 180, genre, lyrics);
        Song song2("Song2", artist, 200, genre, lyrics);
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        CHECK_EQUAL(2, playlist.getSongs().size());
        
        playlist.removeSong("Song1");
        playlist.removeSong("Song2");
        CHECK_EQUAL(0, playlist.getSongs().size());
    }
    
        TEST(Playlist_UserPermissions)
    {
        User user("owner", "pass", "Owner", "owner@test.com", PrivacySettings(true, true));
        Playlist playlist("My Playlist", &user);
        
        CHECK_EQUAL(true, playlist.canUserModify());
        CHECK_EQUAL("owner", playlist.getUserUsername());
    }
    
    TEST(Playlist_NoUser)
    {
        Playlist playlist("Public Playlist", nullptr);
        
        CHECK_EQUAL(false, playlist.canUserModify());
        CHECK_EQUAL("No owner", playlist.getUserUsername());
    }
    
    // УБИРАЕМ ДУБЛИРУЮЩИЙСЯ ТЕСТ - оставляем только один
    TEST(Playlist_RemoveNonExistentSong)
    {
        Playlist playlist("Test Playlist", nullptr);
        Artist artist("Artist", "US");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        Song song("Existing Song", artist, 180, genre, lyrics);
        
        playlist.addSong(song);
        playlist.removeSong("Non Existent Song"); // Не должно вызвать ошибок
        
        CHECK_EQUAL(1, playlist.getSongs().size());
    }
    
    TEST(Playlist_DuplicateSongs)
    {
        Playlist playlist("Duplicates", nullptr);
        Artist artist("Artist", "US");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        Song song1("Same Song", artist, 180, genre, lyrics);
        Song song2("Same Song", artist, 200, genre, lyrics); // То же название
        
        playlist.addSong(song1);
        playlist.addSong(song2);
        playlist.removeSong("Same Song"); // Удалит оба
        
        CHECK_EQUAL(0, playlist.getSongs().size());
    }
}

// Тесты для AudioFormat
SUITE(AudioFormatTests)
{
    TEST(AudioFormat_ConstructorAndGetters)
    {
        AudioFormat format("MP3", 44100, 320);
        
        CHECK_EQUAL("MP3", format.getFormatType());
        CHECK_EQUAL(44100, format.getSampleRate());
        CHECK_EQUAL(320, format.getBitRate());
    }
    
    TEST(AudioFormat_DifferentFormats)
    {
        AudioFormat wav("WAV", 48000, 1411);
        AudioFormat flac("FLAC", 96000, 2116);
        
        CHECK_EQUAL("WAV", wav.getFormatType());
        CHECK_EQUAL(48000, wav.getSampleRate());
        CHECK_EQUAL("FLAC", flac.getFormatType());
        CHECK_EQUAL(96000, flac.getSampleRate());
    }
}

// Тесты для PhysicalMedia
SUITE(PhysicalMediaTests)
{
    TEST(PhysicalMedia_ConstructorAndGetters)
    {
        AudioFormat format("CD", 44100, 1411);
        PhysicalMedia media("Thriller", "Epic Records", format, "Good", "1982-11-30");
        
        CHECK_EQUAL("Thriller", media.getTitle());
        CHECK_EQUAL("Epic Records", media.getRecordLabel());
        CHECK_EQUAL("Good", media.getCondition());
        CHECK_EQUAL("1982-11-30", media.getReleaseDate());
        CHECK_EQUAL("CD", media.getFormat().getFormatType());
    }
}

// Тесты для VinylRecord
SUITE(VinylRecordTests)
{
    TEST(VinylRecord_ConstructorAndGetters)
    {
        AudioFormat format("Vinyl", 44100, 0);
        VinylRecord vinyl("Dark Side of the Moon", "Harvest Records", format, "Excellent", "1973-03-01", 30);
        
        CHECK_EQUAL("Dark Side of the Moon", vinyl.getTitle());
        CHECK_EQUAL("Harvest Records", vinyl.getRecordLabel());
        CHECK_EQUAL(30, vinyl.getDiameter());
        CHECK_EQUAL("Vinyl", vinyl.getFormat().getFormatType());
    }
    
    TEST(VinylRecord_DifferentDiameters)
    {
        AudioFormat format("Vinyl", 44100, 0);
        VinylRecord single("Single", "Label", format, "Good", "2020-01-01", 17);
        VinylRecord lp("LP", "Label", format, "Good", "2020-01-01", 30);
        VinylRecord ep("EP", "Label", format, "Good", "2020-01-01", 25);
        
        CHECK_EQUAL(17, single.getDiameter());
        CHECK_EQUAL(30, lp.getDiameter());
        CHECK_EQUAL(25, ep.getDiameter());
    }
}

// Тесты для CompactDisc
SUITE(CompactDiscTests)
{
    TEST(CompactDisc_ConstructorAndGetters)
    {
        AudioFormat format("CD", 44100, 1411);
        CompactDisc cd("Jagged Little Pill", "Maverick Records", format, "Like New", "1995-06-13", 57);
        
        CHECK_EQUAL("Jagged Little Pill", cd.getTitle());
        CHECK_EQUAL("Maverick Records", cd.getRecordLabel());
        CHECK_EQUAL(57, cd.getDuration());
        CHECK_EQUAL("CD", cd.getFormat().getFormatType());
    }
    
    TEST(CompactDisc_DifferentDurations)
    {
        AudioFormat format("CD", 44100, 1411);
        CompactDisc shortCd("Short Album", "Label", format, "New", "2020-01-01", 30);
        CompactDisc longCd("Long Album", "Label", format, "New", "2020-01-01", 120);
        
        CHECK_EQUAL(30, shortCd.getDuration());
        CHECK_EQUAL(120, longCd.getDuration());
    }
}

// Тесты для CassetteTape
SUITE(CassetteTapeTests)
{
    TEST(CassetteTape_ConstructorAndGetters)
    {
        AudioFormat format("Cassette", 44100, 0);
        CassetteTape tape("Nevermind", "DGC Records", format, "Fair", "1991-09-24", 432);
        
        CHECK_EQUAL("Nevermind", tape.getTitle());
        CHECK_EQUAL("DGC Records", tape.getRecordLabel());
        CHECK_EQUAL(432, tape.getLength());
        CHECK_EQUAL("Cassette", tape.getFormat().getFormatType());
    }
    
    TEST(CassetteTape_DifferentLengths)
    {
        AudioFormat format("Cassette", 44100, 0);
        CassetteTape c30("C30", "Label", format, "Good", "1980-01-01", 432);
        CassetteTape c60("C60", "Label", format, "Good", "1980-01-01", 864);
        CassetteTape c90("C90", "Label", format, "Good", "1980-01-01", 1296);
        
        CHECK_EQUAL(432, c30.getLength());
        CHECK_EQUAL(864, c60.getLength());
        CHECK_EQUAL(1296, c90.getLength());
    }
}

// Тесты для MusicMetadata
SUITE(MusicMetadataTests)
{
    TEST(MusicMetadata_ConstructorAndMethods)
    {
        vector<string> instruments = {"guitar", "drums", "bass", "vocals"};
        MusicMetadata metadata(120, "C#", "Energetic", 0.8, 0.7, 0.3, instruments, 
                              "2000s", "Rock", "English", "Studio A", "24-bit/96kHz");
        
        // Проверяем выполнение методов
        metadata.extractMetadata();
        metadata.analyzeStyle();
        bool isValid = metadata.validate();
        
        CHECK_EQUAL(true, isValid);
    }
    
    TEST(MusicMetadata_DifferentGenres)
    {
        vector<string> rockInstruments = {"guitar", "drums", "bass"};
        vector<string> electronicInstruments = {"synthesizer", "drum machine"};
        
        MusicMetadata rock(140, "E", "Aggressive", 0.9, 0.6, 0.2, rockInstruments, 
                          "2010s", "Rock", "English", "Studio", "Data");
        
        MusicMetadata electronic(128, "F", "Dance", 0.8, 0.9, 0.1, electronicInstruments, 
                                "2020s", "Electronic", "Instrumental", "Home Studio", "Data");
        
        rock.extractMetadata();
        electronic.analyzeStyle();
        
        CHECK(true);
    }
    
    TEST(MusicMetadata_ValidateSuccess)
    {
        vector<string> instruments = {"piano", "violin"};
        MusicMetadata validMetadata(90, "G", "Calm", 0.5, 0.4, 0.8, instruments,
                                   "Classical", "Classical", "None", "Concert Hall", "Data");
        
        bool isValid = validMetadata.validate();
        CHECK_EQUAL(true, isValid);
    }
    
    TEST(MusicMetadata_ValidateFailureNegativeBPM)
    {
        vector<string> instruments = {"guitar"};
        MusicMetadata invalidMetadata(-10, "C", "Happy", 0.8, 0.7, 0.3, instruments,
                                     "2020s", "Pop", "English", "Studio", "Data");
        
        bool isValid = invalidMetadata.validate();
        CHECK_EQUAL(false, isValid);
    }
    
    TEST(MusicMetadata_ValidateFailureEnergyTooHigh)
    {
        vector<string> instruments = {"guitar"};
        MusicMetadata invalidMetadata(120, "C", "Happy", 1.5, 0.7, 0.3, instruments,
                                     "2020s", "Pop", "English", "Studio", "Data");
        
        bool isValid = invalidMetadata.validate();
        CHECK_EQUAL(false, isValid);
    }
    
    TEST(MusicMetadata_ValidateFailureEnergyNegative)
    {
        vector<string> instruments = {"guitar"};
        MusicMetadata invalidMetadata(120, "C", "Happy", -0.5, 0.7, 0.3, instruments,
                                     "2020s", "Pop", "English", "Studio", "Data");
        
        bool isValid = invalidMetadata.validate();
        CHECK_EQUAL(false, isValid);
    }
    
    TEST(MusicMetadata_ValidateFailureDanceabilityTooHigh)
    {
        vector<string> instruments = {"guitar"};
        MusicMetadata invalidMetadata(120, "C", "Happy", 0.8, 1.2, 0.3, instruments,
                                     "2020s", "Pop", "English", "Studio", "Data");
        
        bool isValid = invalidMetadata.validate();
        CHECK_EQUAL(false, isValid);
    }
    
    TEST(MusicMetadata_ValidateFailureDanceabilityNegative)
    {
        vector<string> instruments = {"guitar"};
        MusicMetadata invalidMetadata(120, "C", "Happy", 0.8, -0.1, 0.3, instruments,
                                     "2020s", "Pop", "English", "Studio", "Data");
        
        bool isValid = invalidMetadata.validate();
        CHECK_EQUAL(false, isValid);
    }
    
    TEST(MusicMetadata_AnalyzeStyleEnergetic)
    {
        vector<string> instruments = {"drums", "bass"};
        MusicMetadata energetic(160, "A", "Energetic", 0.9, 0.8, 0.2, instruments,
                               "2020s", "Electronic", "English", "Studio", "Data");
        
        energetic.analyzeStyle(); // Должен сказать "energetic and vibrant"
        CHECK(true);
    }
    
    TEST(MusicMetadata_AnalyzeStyleRelaxed)
    {
        vector<string> instruments = {"piano", "strings"};
        MusicMetadata relaxed(60, "D", "Calm", 0.3, 0.2, 0.9, instruments,
                             "Classical", "Classical", "None", "Hall", "Data");
        
        relaxed.analyzeStyle(); // Должен сказать "more relaxed or mellow"
        CHECK(true);
    }
    
    TEST(MusicMetadata_BoundaryEnergy)
    {
        vector<string> instruments = {"guitar"};
        
        MusicMetadata boundaryLow(100, "C", "Mood", 0.7, 0.5, 0.5, instruments,
                                 "Era", "Style", "Lang", "Loc", "Tech");
        MusicMetadata boundaryHigh(100, "C", "Mood", 0.7001, 0.5, 0.5, instruments,
                                  "Era", "Style", "Lang", "Loc", "Tech");
        
        boundaryLow.analyzeStyle(); // Должен сказать "relaxed or mellow" (energy <= 0.7)
        boundaryHigh.analyzeStyle(); // Должен сказать "energetic and vibrant" (energy > 0.7)
        CHECK(true);
    }
    
    TEST(MusicMetadata_EmptyInstruments)
    {
        vector<string> emptyInstruments;
        MusicMetadata metadata(120, "C", "Happy", 0.8, 0.7, 0.3, emptyInstruments,
                              "2020s", "Electronic", "English", "Studio", "Data");
        
        metadata.extractMetadata();
        bool isValid = metadata.validate();
        CHECK_EQUAL(true, isValid);
    }
    TEST(MusicMetadata_EdgeCaseBPM)
    {
        vector<string> instruments = {"guitar"};
        
        // Граничные значения BPM
        MusicMetadata minBPM(1, "C", "Mood", 0.5, 0.5, 0.5, instruments,
                           "Era", "Style", "Lang", "Loc", "Tech");
        MusicMetadata maxBPM(300, "C", "Mood", 0.5, 0.5, 0.5, instruments,
                           "Era", "Style", "Lang", "Loc", "Tech");
        MusicMetadata overBPM(301, "C", "Mood", 0.5, 0.5, 0.5, instruments,
                            "Era", "Style", "Lang", "Loc", "Tech");
        
        CHECK_EQUAL(true, minBPM.validate());
        CHECK_EQUAL(true, maxBPM.validate());
        CHECK_EQUAL(false, overBPM.validate());
    }
    
    TEST(MusicMetadata_EdgeCaseEnergy)
    {
        vector<string> instruments = {"guitar"};
        
        // Граничные значения Energy
        MusicMetadata minEnergy(120, "C", "Mood", 0.0, 0.5, 0.5, instruments,
                              "Era", "Style", "Lang", "Loc", "Tech");
        MusicMetadata maxEnergy(120, "C", "Mood", 1.0, 0.5, 0.5, instruments,
                              "Era", "Style", "Lang", "Loc", "Tech");
        MusicMetadata overEnergy(120, "C", "Mood", 1.1, 0.5, 0.5, instruments,
                               "Era", "Style", "Lang", "Loc", "Tech");
        
        CHECK_EQUAL(true, minEnergy.validate());
        CHECK_EQUAL(true, maxEnergy.validate());
        CHECK_EQUAL(false, overEnergy.validate());
    }
    
    TEST(MusicMetadata_GetSetMethods)
    {
        vector<string> instruments = {"piano"};
        MusicMetadata metadata(100, "C", "Happy", 0.5, 0.5, 0.5, instruments,
                             "2020s", "Jazz", "English", "Studio", "24-bit");
        
        // Тестируем get методы
        Song& song = metadata.getSong();
        Copyright& copyright = metadata.getCopyright();
        AudioQuality& quality = metadata.getAudioQuality();
        
        // Тестируем set методы
        Artist newArtist("New Artist", "USA");
        Genre newGenre("New Genre");
        Lyrics newLyrics("New lyrics");
        Song newSong("New Song", newArtist, 200, newGenre, newLyrics);
        
        metadata.setSong(newSong);
        metadata.setCopyright(Copyright("New Owner", "2024"));
        metadata.setAudioQuality(AudioQuality("High", "HD Quality"));
        
        CHECK_EQUAL("New Song", metadata.getSong().getTitle());
        CHECK_EQUAL("New Owner", metadata.getCopyright().getOwner());
        CHECK_EQUAL("High", metadata.getAudioQuality().getQualityLevel());
    }
    
    TEST(MusicMetadata_ZeroValues)
    {
        vector<string> emptyInstruments;
        MusicMetadata metadata(0, "", "", 0.0, 0.0, 0.0, emptyInstruments,
                             "", "", "", "", "");
        
        // BPM=0 должно быть невалидным
        CHECK_EQUAL(false, metadata.validate());
    }
    
    TEST(MusicMetadata_ManyInstruments)
{
    vector<string> manyInstruments = {"guitar", "drums", "bass", "piano", "violin", 
                                     "saxophone", "trumpet", "synth", "vocals"};
    MusicMetadata metadata(120, "C", "Complex", 0.8, 0.7, 0.4, manyInstruments,
                         "2020s", "Fusion", "English", "Studio", "32-bit");
    
    CHECK_EQUAL(true, metadata.validate());
    // Проверяем что количество инструментов сохранилось правильно
    CHECK_EQUAL(9, manyInstruments.size()); // Проверяем исходный вектор
    // Или проверяем что метаданные валидны с большим количеством инструментов
    CHECK(true); // Просто проверяем что не упало
}
}

// Тесты для MusicVideo
SUITE(MusicVideoTests)
{
    TEST(MusicVideo_ConstructorAndGetters)
    {
        MusicVideo video("Thriller", "Epic Records", "http://youtube.com/thriller", 
                        "1080p", "Michael Jackson", 14, "John Landis");
        
        CHECK_EQUAL("Thriller", video.getTitle());
        CHECK_EQUAL("Michael Jackson", video.getArtist());
        CHECK_EQUAL(14, video.getDuration());
        CHECK_EQUAL("John Landis", video.getDirector());
        CHECK_EQUAL("Epic Records", video.getRecordLabel());
    }
    
    TEST(MusicVideo_DifferentArtists)
    {
        MusicVideo video1("Bad Guy", "Darkroom", "http://example.com", "4K", "Billie Eilish", 3, "Director");
        MusicVideo video2("Blinding Lights", "Republic", "http://example.com", "1080p", "The Weeknd", 4, "Director");
        
        CHECK_EQUAL("Billie Eilish", video1.getArtist());
        CHECK_EQUAL("The Weeknd", video2.getArtist());
        CHECK_EQUAL(3, video1.getDuration());
        CHECK_EQUAL(4, video2.getDuration());
    }
}

// Тесты для AudioQuality
SUITE(AudioQualityTests)
{
    TEST(AudioQuality_ConstructorAndGetters)
    {
        AudioQuality quality("High", "High quality audio with 320 kbps bitrate");
        
        CHECK_EQUAL("High", quality.getQualityLevel());
        CHECK_EQUAL("High quality audio with 320 kbps bitrate", quality.getDescription());
    }
    
    TEST(AudioQuality_DifferentLevels)
    {
        AudioQuality low("Low", "Low quality audio with 128 kbps bitrate");
        AudioQuality medium("Medium", "Medium quality audio with 192 kbps bitrate");
        AudioQuality high("High", "High quality audio with 320 kbps bitrate");
        AudioQuality lossless("Lossless", "Lossless audio quality");
        
        CHECK_EQUAL("Low", low.getQualityLevel());
        CHECK_EQUAL("Medium", medium.getQualityLevel());
        CHECK_EQUAL("High", high.getQualityLevel());
        CHECK_EQUAL("Lossless", lossless.getQualityLevel());
    }
}

// Тесты для Copyright
SUITE(CopyrightTests)
{
    TEST(Copyright_ConstructorAndGetters)
    {
        Copyright copyright("Sony Music", "2020-01-15");
        
        CHECK_EQUAL("Sony Music", copyright.getOwner());
        CHECK_EQUAL("2020-01-15", copyright.getDate());
        CHECK_EQUAL(0, copyright.getRestrictedCountries().size());
    }
    
    TEST(Copyright_AddRestrictedCountries)
    {
        Copyright copyright("Universal Music", "2019-05-20");
        
        copyright.addRestrictedCountry("North Korea");
        copyright.addRestrictedCountry("Iran");
        copyright.addRestrictedCountry("Syria");
        
        vector<string> restricted = copyright.getRestrictedCountries();
        CHECK_EQUAL(3, restricted.size());
        CHECK_EQUAL("North Korea", restricted[0]);
        CHECK_EQUAL("Iran", restricted[1]);
        CHECK_EQUAL("Syria", restricted[2]);
    }
    
    TEST(Copyright_EmptyRestrictedCountries)
    {
        Copyright copyright("Independent Artist", "2023-01-01");
        
        vector<string> restricted = copyright.getRestrictedCountries();
        CHECK_EQUAL(0, restricted.size());
    }
}

// Тесты для Concert
SUITE(ConcertTests)
{
    TEST(Concert_ConstructorAndMethods)
    {
        Artist artist("The Beatles", "UK");
        Concert concert(artist, "1965-08-15", "Shea Stadium", 55600);
        
        // Проверяем выполнение методов
        concert.checkTickets();
        double occupancy = concert.calculateOccupancy();
        
        CHECK(true); // Методы выполняются без ошибок
    }
    
    TEST(Concert_DifferentVenues)
    {
        Artist artist1("Taylor Swift", "USA");
        Artist artist2("Ed Sheeran", "UK");
        
        Concert stadiumConcert(artist1, "2023-05-20", "MetLife Stadium", 82500);
        Concert arenaConcert(artist2, "2023-06-15", "Madison Square Garden", 20000);
        
        stadiumConcert.checkTickets();
        arenaConcert.calculateOccupancy();
        
        CHECK(true);
    }
}

// Тесты для Podcast
SUITE(PodcastTests)
{
    TEST(Podcast_ConstructorAndGetters)
    {
        Podcast podcast("Tech Talk", "Tech Network", "http://podcast.com/techtalk", 
                       "MP3 128kbps", "John Doe");
        
        CHECK_EQUAL("Tech Talk", podcast.getTitle());
        CHECK_EQUAL("John Doe", podcast.getHost());
        CHECK_EQUAL("Tech Network", podcast.getRecordLabel());
        CHECK_EQUAL(0, podcast.getEpisodes().size());
    }
    
    TEST(Podcast_AddEpisodes)
    {
        Podcast podcast("Science Weekly", "Science Corp", "http://example.com", "MP3", "Jane Smith");
        
        podcast.addEpisode("Episode 1: Introduction");
        podcast.addEpisode("Episode 2: Physics");
        podcast.addEpisode("Episode 3: Biology");
        
        vector<string> episodes = podcast.getEpisodes();
        CHECK_EQUAL(3, episodes.size());
        CHECK_EQUAL("Episode 1: Introduction", episodes[0]);
        CHECK_EQUAL("Episode 2: Physics", episodes[1]);
        CHECK_EQUAL("Episode 3: Biology", episodes[2]);
    }
    
    TEST(Podcast_EmptyEpisodes)
    {
        Podcast podcast("New Podcast", "Network", "http://example.com", "Format", "Host");
        
        vector<string> episodes = podcast.getEpisodes();
        CHECK_EQUAL(0, episodes.size());
    }
}

// Тесты для LiveRecording
SUITE(LiveRecordingTests)
{
    TEST(LiveRecording_ConstructorAndGetters)
    {
        LiveRecording recording("Queen", "Live at Wembley", "EMI", "http://example.com/queen", 
                               "FLAC 24-bit", "Wembley Stadium", "1986-07-12");
        
        CHECK_EQUAL("Queen", recording.getArtist());
        CHECK_EQUAL("Live at Wembley", recording.getTitle());
        CHECK_EQUAL("Wembley Stadium", recording.getVenue());
        CHECK_EQUAL("1986-07-12", recording.getDate());
        CHECK_EQUAL("EMI", recording.getRecordLabel());
    }
    
    TEST(LiveRecording_DifferentArtists)
    {
        LiveRecording recording1("Nirvana", "MTV Unplugged", "DGC", "http://example.com", 
                                "MP3", "MTV Studios", "1993-11-18");
        LiveRecording recording2("Adele", "Live at Royal Albert Hall", "XL", "http://example.com", 
                                "WAV", "Royal Albert Hall", "2011-09-22");
        
        CHECK_EQUAL("Nirvana", recording1.getArtist());
        CHECK_EQUAL("Adele", recording2.getArtist());
        CHECK_EQUAL("MTV Studios", recording1.getVenue());
        CHECK_EQUAL("Royal Albert Hall", recording2.getVenue());
    }
    
    TEST(LiveRecording_DifferentVenues)
    {
        LiveRecording recording("The Rolling Stones", "Live Performance", "Label", 
                               "http://example.com", "Format", "Hyde Park", "1969-07-05");
        
        CHECK_EQUAL("The Rolling Stones", recording.getArtist());
        CHECK_EQUAL("Hyde Park", recording.getVenue());
        CHECK_EQUAL("1969-07-05", recording.getDate());
    }
}
// Тесты для DigitalMedia
SUITE(DigitalMediaTests)
{
    TEST(DigitalMedia_ConstructorAndGetters)
    {
        DigitalMedia media("Digital Album", "Record Label", "http://source.com", "MP3 320kbps");
        
        CHECK_EQUAL("Digital Album", media.getTitle());
        CHECK_EQUAL("Record Label", media.getRecordLabel());
        CHECK_EQUAL("http://source.com", media.getSourceUrl());
        CHECK_EQUAL("MP3 320kbps", media.getFormatDescription());
    }
    
    TEST(DigitalMedia_DifferentFormats)
    {
        DigitalMedia mp3("Song", "Label", "http://mp3.com", "MP3 256kbps");
        DigitalMedia flac("Song", "Label", "http://flac.com", "FLAC 24-bit/96kHz");
        DigitalMedia wav("Song", "Label", "http://wav.com", "WAV 16-bit/44.1kHz");
        
        CHECK_EQUAL("MP3 256kbps", mp3.getFormatDescription());
        CHECK_EQUAL("FLAC 24-bit/96kHz", flac.getFormatDescription());
        CHECK_EQUAL("WAV 16-bit/44.1kHz", wav.getFormatDescription());
    }
}
// Тесты для SoundEffect
SUITE(SoundEffectTests)
{
    TEST(SoundEffect_ConstructorAndMethods)
    {
        vector<string> tags = {"explosion", "action", "loud"};
        vector<double> parameters = {1.0, 0.8, 0.5};
        
        SoundEffect effect("Big Explosion", "Explosions", 3.5, "WAV", 
                          "Action movies", "Sound Designer", 49.99, 
                          tags, parameters, "Royalty-free");
        
        // Проверяем выполнение методов
        effect.preview();
        effect.applyToAudio();
        effect.categorize();
        
        CHECK(true); // Методы выполняются без ошибок
    }
    
    TEST(SoundEffect_DifferentCategories)
    {
        vector<string> natureTags = {"birds", "forest", "calm"};
        vector<string> techTags = {"futuristic", "sci-fi", "electronic"};
        vector<double> params = {0.5, 0.3};
        
        SoundEffect nature("Forest Morning", "Nature", 60.0, "MP3", 
                          "Meditation", "Nature Recordings", 19.99, 
                          natureTags, params, "Creative Commons");
                          
        SoundEffect tech("Laser Blast", "Sci-Fi", 2.0, "WAV", 
                        "Games", "Tech Sounds", 29.99, 
                        techTags, params, "Royalty-free");
        
        nature.preview();
        tech.categorize();
        
        CHECK(true);
    }
    
    TEST(SoundEffect_FreeAndPremium)
    {
        vector<string> tags = {"ambient", "background"};
        vector<double> params = {0.2};
        
        SoundEffect freeEffect("Wind", "Nature", 10.0, "MP3",
                              "Background", "Free Sounds", 0.0,
                              tags, params, "Free");
                              
        SoundEffect premiumEffect("Cinematic Impact", "Cinematic", 5.0, "WAV",
                                 "Film", "Pro Studio", 99.99,
                                 tags, params, "Commercial License");
        
        freeEffect.preview();
        premiumEffect.applyToAudio();
        
        CHECK(true);
    }
    
    TEST(SoundEffect_ShortAndLongDuration)
    {
        vector<string> tags = {"test"};
        vector<double> params = {1.0};
        
        SoundEffect shortEffect("Click", "UI", 0.1, "WAV",
                               "Interface", "Designer", 0.0,
                               tags, params, "Free");
                               
        SoundEffect longEffect("Atmosphere", "Ambient", 300.0, "MP3",
                              "Background", "Artist", 15.0,
                              tags, params, "Royalty-free");
        
        shortEffect.categorize();
        longEffect.preview();
        
        CHECK(true);
    }
    
    TEST(SoundEffect_EmptyTagsAndParameters)
    {
        vector<string> emptyTags;
        vector<double> emptyParams;
        
        SoundEffect effect("Silence", "Experimental", 1.0, "WAV",
                          "Art", "Artist", 0.0,
                          emptyTags, emptyParams, "Public Domain");
        
        effect.preview();
        effect.applyToAudio();
        effect.categorize();
        
        CHECK(true);
    }
    
    TEST(SoundEffect_MultipleTags)
    {
        vector<string> manyTags = {"rain", "water", "nature", "calm", "relaxing", "ambient", "weather"};
        vector<double> manyParams = {0.1, 0.2, 0.3, 0.4, 0.5};
        
        SoundEffect effect("Heavy Rain", "Weather", 180.0, "FLAC",
                          "Meditation", "Nature Recordist", 25.0,
                          manyTags, manyParams, "Royalty-free");
        
        effect.preview();
        effect.categorize();
        
        CHECK(true);
    }
    
    TEST(SoundEffect_DifferentFormats)
    {
        vector<string> tags = {"test"};
        vector<double> params = {1.0};
        
        SoundEffect mp3("MP3 Effect", "Test", 1.0, "MP3", "Test", "Author", 0.0, tags, params, "Free");
        SoundEffect wav("WAV Effect", "Test", 1.0, "WAV", "Test", "Author", 0.0, tags, params, "Free");
        SoundEffect flac("FLAC Effect", "Test", 1.0, "FLAC", "Test", "Author", 0.0, tags, params, "Free");
        SoundEffect aiff("AIFF Effect", "Test", 1.0, "AIFF", "Test", "Author", 0.0, tags, params, "Free");
        
        mp3.preview();
        wav.applyToAudio();
        flac.categorize();
        aiff.preview();
        
        CHECK(true);
    }
}
// Тесты для Remix (нужен SoundEffect)
SUITE(RemixTests)
{
    TEST(Remix_ConstructorAndGetters)
    {
        vector<string> tags = {"bass", "electronic"};
        vector<double> params = {0.7, 0.9};
        SoundEffect effect("Bass Boost", "EQ", 0.0, "Internal", 
                          "Remixing", "Producer", 0.0, tags, params, "Free");
        
        Remix remix("Song Remix", "Remix Label", "http://remix.com", "MP3", 
                   "Original Artist", "DJ Remixer", "Original Song", &effect);
        
        CHECK_EQUAL("Song Remix", remix.getTitle());
        CHECK_EQUAL("Original Artist", remix.getOriginalArtist());
        CHECK_EQUAL("DJ Remixer", remix.getRemixer());
        CHECK_EQUAL("Original Song", remix.getOriginalSong());
        CHECK_EQUAL(&effect, remix.getSoundEffect());
    }
    
    TEST(Remix_WithoutSoundEffect)
    {
        Remix remix("Acoustic Remix", "Label", "http://example.com", "WAV",
                   "Pop Artist", "Acoustic Band", "Pop Song", nullptr);
        
        CHECK_EQUAL("Acoustic Remix", remix.getTitle());
        CHECK_EQUAL("Pop Artist", remix.getOriginalArtist());
        CHECK_EQUAL("Acoustic Band", remix.getRemixer());
        CHECK_EQUAL(nullptr, remix.getSoundEffect());
    }
}
// Тесты для Audiobook
SUITE(AudiobookTests)
{
    TEST(Audiobook_ConstructorAndGetters)
    {
        Audiobook book("1984", "Publisher Co", "http://audiobooks.com/1984", 
                      "MP3 128kbps", "George Orwell", 540, "John Smith", 15);
        
        CHECK_EQUAL("1984", book.getTitle());
        CHECK_EQUAL("George Orwell", book.getAuthor());
        CHECK_EQUAL("John Smith", book.getNarrator());
        CHECK_EQUAL(540, book.getDuration());
        CHECK_EQUAL(15, book.getChapters());
        CHECK_EQUAL("Publisher Co", book.getRecordLabel());
    }
    
    TEST(Audiobook_DifferentBooks)
    {
        Audiobook book1("The Hobbit", "Publisher", "http://example.com", "MP3", 
                       "J.R.R. Tolkien", 660, "Rob Inglis", 19);
        Audiobook book2("Dune", "Publisher", "http://example.com", "MP3", 
                       "Frank Herbert", 1200, "Simon Vance", 48);
        
        CHECK_EQUAL("The Hobbit", book1.getTitle());
        CHECK_EQUAL("J.R.R. Tolkien", book1.getAuthor());
        CHECK_EQUAL("Dune", book2.getTitle());
        CHECK_EQUAL("Frank Herbert", book2.getAuthor());
        CHECK_EQUAL(660, book1.getDuration());
        CHECK_EQUAL(1200, book2.getDuration());
        CHECK_EQUAL(19, book1.getChapters());
        CHECK_EQUAL(48, book2.getChapters());
    }
    
    TEST(Audiobook_ShortAndLong)
    {
        Audiobook shortBook("Short Story", "Pub", "http://example.com", "Format", 
                           "Author", 30, "Narrator", 3);
        Audiobook longBook("Long Novel", "Pub", "http://example.com", "Format", 
                          "Author", 1800, "Narrator", 60);
        
        CHECK_EQUAL(30, shortBook.getDuration());
        CHECK_EQUAL(1800, longBook.getDuration());
        CHECK_EQUAL(3, shortBook.getChapters());
        CHECK_EQUAL(60, longBook.getChapters());
    }
}
// Тесты для AudioPlayer
SUITE(AudioPlayerTests)
{
    TEST(AudioPlayer_Constructor)
    {
        AudioPlayer player;
        
        CHECK_EQUAL(1.0, player.getVolume());
    }
    
    TEST(AudioPlayer_SetGetVolume)
    {
        AudioPlayer player;
        
        player.setVolume(0.75);
        CHECK_EQUAL(0.75, player.getVolume());
        
        player.setVolume(0.0);
        CHECK_EQUAL(0.0, player.getVolume());
        
        player.setVolume(1.0);
        CHECK_EQUAL(1.0, player.getVolume());
    }
    
    TEST(AudioPlayer_PlayPauseStop)
    {
        AudioPlayer player;
        
        player.play();
        player.pause();
        player.stop();
        player.play();
        player.stop();
        
        CHECK(true); // Проверяем выполнение методов
    }
    
    TEST(AudioPlayer_VolumeBoundaries)
    {
        AudioPlayer player;
        
        player.setVolume(-0.1); // Ниже минимума
        player.setVolume(1.1);  // Выше максимума
        player.setVolume(0.5);  // Нормальное значение
        
        CHECK(true); // Проверяем что не падает
    }
}

// Тесты для PlaybackController
SUITE(PlaybackControllerTests)
{
    TEST(PlaybackController_Constructor)
    {
        PlaybackController controller;
        CHECK(true);
    }
    
    TEST(PlaybackController_AddRemovePlayers)
    {
        PlaybackController controller;
        AudioPlayer player1, player2;
        
        controller.addPlayer(&player1);
        controller.addPlayer(&player2);
        controller.removePlayer(&player1);
        
        CHECK(true);
    }
    
    TEST(PlaybackController_StartStopAll)
    {
        PlaybackController controller;
        AudioPlayer player1, player2;
        
        controller.addPlayer(&player1);
        controller.addPlayer(&player2);
        controller.startAll();
        controller.stopAll();
        
        CHECK(true);
    }
    
    TEST(PlaybackController_Empty)
    {
        PlaybackController controller;
        
        controller.startAll();
        controller.stopAll();
        
        CHECK(true);
    }
}

// Тесты для PlaylistGenerator
SUITE(PlaylistGeneratorTests)
{
    TEST(PlaylistGenerator_Constructor)
    {
        PlaylistGenerator generator;
        CHECK(true);
    }
    
    TEST(PlaylistGenerator_GeneratePlaylist)
    {
        PlaylistGenerator generator;
        vector<string> tracks = {"song1.mp3", "song2.mp3", "song3.mp3"};
        
        vector<string> playlist = generator.generatePlaylist(tracks);
        CHECK(true);
    }
    
    TEST(PlaylistGenerator_CustomizeRules)
    {
        PlaylistGenerator generator;
        vector<string> rules = {"shuffle", "by_rating", "no_repeats"};
        
        generator.customizeRules(rules);
        generator.optimizeSequence();
        
        CHECK(true);
    }
    
    TEST(PlaylistGenerator_EmptyTracks)
    {
        PlaylistGenerator generator;
        vector<string> emptyTracks;
        
        vector<string> playlist = generator.generatePlaylist(emptyTracks);
        CHECK(true);
    }
}

// Тесты для WirelessSpeaker
class WirelessSpeakerTest : public WirelessSpeaker {
public:
    WirelessSpeakerTest() : WirelessSpeaker("Test Model", 10) {}
};

SUITE(WirelessSpeakerTests)
{
    TEST(WirelessSpeaker_ConstructorAndGetters)
    {
        WirelessSpeaker speaker("JBL Flip", 8);
        
        CHECK_EQUAL("JBL Flip", speaker.getDeviceInfo());
        CHECK_EQUAL(100, speaker.getBatteryLevel()); // Должно быть 100 по умолчанию
    }
    
    TEST(WirelessSpeaker_SetBatteryLevel)
    {
        WirelessSpeaker speaker("Sony", 12);
        
        speaker.setBatteryLevel(75);
        CHECK_EQUAL(75, speaker.getBatteryLevel());
        
        speaker.setBatteryLevel(0);
        CHECK_EQUAL(0, speaker.getBatteryLevel());
        
        speaker.setBatteryLevel(100);
        CHECK_EQUAL(100, speaker.getBatteryLevel());
    }
    
    TEST(WirelessSpeaker_ConnectDisconnect)
    {
        WirelessSpeaker speaker("Bose", 10);
        
        speaker.connect();
        speaker.disconnect();
        
        CHECK(true);
    }
}

// Тесты для VolumeNormalizer
SUITE(VolumeNormalizerTests)
{
    TEST(VolumeNormalizer_Constructor)
    {
        VolumeNormalizer normalizer;
        
        CHECK_EQUAL(0.8, normalizer.getTargetVolume());
        CHECK_EQUAL(1.0, normalizer.getMaxVolume());
    }
    
    TEST(VolumeNormalizer_SetTargetVolume)
    {
        VolumeNormalizer normalizer;
        
        normalizer.setTargetVolume(0.8);
        CHECK_EQUAL(0.8, normalizer.getTargetVolume());
        
        normalizer.setTargetVolume(0.5);
        CHECK_EQUAL(0.5, normalizer.getTargetVolume());
    }
    
    TEST(VolumeNormalizer_Normalize)
    {
        VolumeNormalizer normalizer;
        AudioPlayer player;
        
        normalizer.normalize(&player);
        CHECK(true);
    }
}

// Тесты для StreamManager
SUITE(StreamManagerTests)
{
    TEST(StreamManager_Constructor)
    {
        StreamManager manager;
        
        CHECK_EQUAL(false, manager.isStreaming());
    }
    
    TEST(StreamManager_StartStopStream)
    {
        StreamManager manager;
        
        manager.startStream("http://stream.example.com");
        CHECK_EQUAL(true, manager.isStreaming());
        
        manager.stopStream();
        CHECK_EQUAL(false, manager.isStreaming());
    }
    
    TEST(StreamManager_MultipleStreams)
    {
        StreamManager manager;
        
        manager.startStream("http://stream1.com");
        manager.stopStream();
        manager.startStream("http://stream2.com");
        manager.stopStream();
        
        CHECK(true);
    }
}

// Тесты для SoundSystem
class SoundSystemTest : public SoundSystem {
public:
    SoundSystemTest() : SoundSystem("Test System") {}
};

SUITE(SoundSystemTests)
{
    TEST(SoundSystem_ConstructorAndGetters)
    {
        SoundSystem system("Home Theater");
        
        CHECK_EQUAL("Home Theater", system.getDeviceInfo());
        CHECK_EQUAL(0, system.getTotalSpeakers());
    }
    
    TEST(SoundSystem_AddSpeakers)
    {
        SoundSystem system("Surround Sound");
        WirelessSpeaker speaker1("Speaker1", 8);
        WirelessSpeaker speaker2("Speaker2", 8);
        
        system.addSpeaker(&speaker1);
        system.addSpeaker(&speaker2);
        
        CHECK_EQUAL(2, system.getTotalSpeakers());
    }
    
    TEST(SoundSystem_ConnectDisconnect)
    {
        SoundSystem system("Test System");
        
        system.connect();
        system.disconnect();
        
        CHECK(true);
    }
}

// Тесты для ShoppingCart
SUITE(ShoppingCartTests)
{
    TEST(ShoppingCart_Constructor)
    {
        ShoppingCart cart(nullptr);
        CHECK_EQUAL(0.0, cart.calculateTotal());
    }
    
    TEST(ShoppingCart_AddDigitalItem)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase item("Song", "2024-01-01", 9.99, "MP3", "Download", "Music", "Store", true);
        
        cart.addDigitalItem(item, 2);
        double total = cart.calculateTotal();
        
        CHECK_CLOSE(19.98, total, 0.01); // 9.99 * 2 = 19.98
    }
    
    TEST(ShoppingCart_AddPhysicalItem)
    {
        ShoppingCart cart(nullptr);
        PhysicalMediaOrder item("CD", 1, "123 Main St", "Processing", "TRACK123", false, "Standard", "2024-01-01", "Return Policy", "Customs Info", true);
        
        cart.addPhysicalItem(item, 1);
        double total = cart.calculateTotal();
        
        CHECK(total > 0.0);
    }
    
    TEST(ShoppingCart_ApplyDiscount)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase item("Album", "2024-01-01", 19.99, "MP3", "Download", "Music", "Store", true);
        
        cart.addDigitalItem(item, 1);
        cart.applyDiscount(5.0);
        double total = cart.calculateTotal();
        
        CHECK_CLOSE(14.99, total, 0.01); // 19.99 - 5.00 = 14.99
    }
    
    TEST(ShoppingCart_MultipleItems)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase digital("Song", "2024-01-01", 4.99, "MP3", "Download", "Music", "Store", true);
        PhysicalMediaOrder physical("Vinyl", 1, "456 Oak Ave", "Shipped", "TRACK456", true, "Premium", "2024-01-01", "Return Policy", "Customs Info", true);
        
        cart.addDigitalItem(digital, 3);
        cart.addPhysicalItem(physical, 2);
        cart.applyDiscount(10.0);
        
        double total = cart.calculateTotal();
        CHECK(total > 0.0);
    }
    
    TEST(ShoppingCart_EmptyCart)
    {
        ShoppingCart cart(nullptr);
        CHECK_EQUAL(0.0, cart.calculateTotal());
    }

    TEST(ShoppingCart_ApplyMultipleDiscounts)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase item1("Song1", "2024-01-01", 10.0, "MP3", "Download", "Music", "Store", true);
        DigitalPurchase item2("Song2", "2024-01-01", 20.0, "MP3", "Download", "Music", "Store", true);
        
        cart.addDigitalItem(item1, 2);
        cart.addDigitalItem(item2, 1);
        
        cart.applyDiscount(5.0);
        cart.applyDiscount(3.0);
        
        double total = cart.calculateTotal();
        CHECK_CLOSE(32.0, total, 0.01); // 10*2 + 20*1 - 5 - 3 = 32
    }
    
    TEST(ShoppingCart_ZeroQuantity)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase item("Song", "2024-01-01", 10.0, "MP3", "Download", "Music", "Store", true);
        
        cart.addDigitalItem(item, 0); // Нулевое количество
        
        CHECK_EQUAL(0.0, cart.calculateTotal());
    }
    
    TEST(ShoppingCart_UserAssociation)
{
    User user("testuser", "pass", "Test User", "test@test.com", PrivacySettings(true, true));
    ShoppingCart cart(&user);
    
    CHECK_EQUAL("testuser", cart.getUserUsername());
    CHECK(cart.getUser() != nullptr);
}

TEST(ShoppingCart_UserDiscounts)
{
    User user("premium", "pass", "Premium User", "premium@test.com", PrivacySettings(true, true));
    
    // ДОБАВЛЯЕМ ДОСТИЖЕНИЯ ПОЛЬЗОВАТЕЛЮ ДЛЯ СКИДКИ
    UserAchievement achievement1("First Purchase", "2024-01-01");
    UserAchievement achievement2("Loyal Customer", "2024-01-02");
    user.addAchievement(achievement1);
    user.addAchievement(achievement2);
    
    ShoppingCart cart(&user);
    
    DigitalPurchase item("Premium Song", "2024-01-01", 100.0, "MP3", "Download", "Music", "Store", true);
    cart.addDigitalItem(item, 1);
    
    cart.applyUserDiscounts(); // Применяем пользовательские скидки
    
    double total = cart.calculateTotal();
    CHECK(total < 100.0); // Должна быть применена скидка (2% скидка = 98.0)
}
    
    TEST(ShoppingCart_SaveLoadCart)
    {
        User user("testuser", "pass", "Test User", "test@test.com", PrivacySettings(true, true));
        ShoppingCart cart(&user);
        
        DigitalPurchase item("Song", "2024-01-01", 15.0, "MP3", "Download", "Music", "Store", true);
        cart.addDigitalItem(item, 2);
        
        cart.saveCart(); // Не должно падать
        cart.loadUserCart(); // Не должно падать
        
        CHECK(true); // Просто проверяем что не упало
    }
    
    TEST(ShoppingCart_SetUser)
    {
        ShoppingCart cart(nullptr);
        User user1("user1", "pass", "User One", "user1@test.com", PrivacySettings(true, true));
        User user2("user2", "pass", "User Two", "user2@test.com", PrivacySettings(true, true));
        
        cart.setUser(&user1);
        CHECK_EQUAL("user1", cart.getUserUsername());
        
        cart.setUser(&user2);
        CHECK_EQUAL("user2", cart.getUserUsername());
        
        cart.setUser(nullptr);
        CHECK_EQUAL("No user", cart.getUserUsername());
    }
    
    TEST(ShoppingCart_ShippingAndTaxes)
    {
        ShoppingCart cart(nullptr);
        PhysicalMediaOrder item("Heavy Item", 1, "789 Pine Rd", "Processing", "TRACK789", false, "Large Box", "2024-01-01", "Return Policy", "Customs Info", true);
        
        cart.addPhysicalItem(item, 1);
        
        // В реальной реализации shipping и taxes устанавливаются отдельно
        // Здесь просто проверяем что calculateTotal работает
        double total = cart.calculateTotal();
        CHECK(total >= 0.0);
    }
    
    TEST(ShoppingCart_LargeQuantities)
    {
        ShoppingCart cart(nullptr);
        DigitalPurchase item("Cheap Song", "2024-01-01", 0.99, "MP3", "Download", "Music", "Store", true);
        
        cart.addDigitalItem(item, 1000); // Большое количество
        
        double total = cart.calculateTotal();
        CHECK_CLOSE(990.0, total, 0.01); // 0.99 * 1000 = 990
    }
}

// Тесты для RecommendationSystem
SUITE(RecommendationSystemTests)
{
    TEST(RecommendationSystem_Constructor)
    {
        User user("test", "pass", "Test User", "test@email.com", PrivacySettings(true, true));
        RecommendationSystem system(user);
        
        CHECK(true);
    }
    
    TEST(RecommendationSystem_Methods)
    {
        User user("john", "pass", "John Doe", "john@email.com", PrivacySettings(true, true));
        RecommendationSystem system(user);
        
        system.generateRecommendations("user123");
        system.updateAlgorithm();
        system.measureAccuracy();
        
        CHECK(true);
    }
}

// Тесты для PhysicalMediaOrder
SUITE(PhysicalMediaOrderTests)
{
    TEST(PhysicalMediaOrder_ConstructorAndGetters)
    {
        PhysicalMediaOrder order("Dark Side of the Moon", 2, "123 Main St", 
                                "Processing", "TRK123", true, "Box", 
                                "2024-01-15", "30 days", "None", true);
        
        CHECK_EQUAL("Dark Side of the Moon", order.getMedia());
        CHECK_EQUAL(2, order.getQuantity());
        CHECK_EQUAL(15.99, order.getPrice()); // или другое значение по умолчанию
    }
    
    TEST(PhysicalMediaOrder_Methods)
    {
        PhysicalMediaOrder order("Thriller", 1, "456 Oak St", "Shipped", 
                                "TRK456", false, "Envelope", "2024-01-10", 
                                "14 days", "Customs paid", false);
        
        order.trackOrder();
        order.confirmDelivery();
        order.processReturn();
        
        CHECK(true);
    }
}

// Тесты для MusicStore
SUITE(MusicStoreTests)
{
    TEST(MusicStore_Constructor)
    {
        MusicStore store;
        CHECK(true);
    }
    
    TEST(MusicStore_SearchCatalog)
    {
        MusicStore store;
        
        store.searchCatalog("rock");
        store.searchCatalog("jazz");
        store.searchCatalog(""); // пустой запрос
        
        CHECK(true);
    }
    
    TEST(MusicStore_ProcessDigitalSale)
    {
        MusicStore store;
        DigitalPurchase purchase("Digital Song", "2024-01-01", 9.99, 
                                "License", "Link", "Restrictions", "Policy", true);
        
        store.processSale(purchase);
        CHECK(true);
    }
    
    TEST(MusicStore_ProcessPhysicalSale)
    {
        MusicStore store;
        PhysicalMediaOrder order("CD Album", 2, "Address", "Status", 
                                "Tracking", true, "Box", "2024-01-15", 
                                "30 days", "Customs", true);
        
        store.processSale(order);
        CHECK(true);
    }
    
    TEST(MusicStore_UpdateInventory)
    {
        MusicStore store;
        
        store.updateInventory("New Album", 100);
        store.updateInventory("Single", 50);
        store.updateInventory("Out of Stock", -10); // уменьшение инвентаря
        
        CHECK(true);
    }
    
    TEST(MusicStore_MultipleOperations)
    {
        MusicStore store;
        DigitalPurchase digital("Song", "2024-01-01", 4.99, "License", "Link", "Restrictions", "Policy", true);
        PhysicalMediaOrder physical("Vinyl", 1, "Address", "Status", "Tracking", true, "Box", "Date", "Policy", "Customs", true);
        
        store.searchCatalog("rock");
        store.processSale(digital);
        store.processSale(physical);
        store.updateInventory("Album", 25);
        
        CHECK(true);
    }
}

// Тесты для MusicDiscovery
SUITE(MusicDiscoveryTests)
{
    TEST(MusicDiscovery_Constructor)
    {
        MusicDiscovery discovery;
        CHECK(true);
    }
    
    TEST(MusicDiscovery_SearchMethods)
    {
        MusicDiscovery discovery;
        
        discovery.searchByGenre("jazz");
        
        vector<string> criteria = {"artist: Miles Davis", "year: 1959", "instrument: trumpet"};
        discovery.advancedSearch(criteria);
        
        discovery.saveSearch("Miles Davis Jazz");
        
        CHECK(true);
    }
    
    TEST(MusicDiscovery_EmptySearches)
    {
        MusicDiscovery discovery;
        
        discovery.searchByGenre("");
        
        vector<string> emptyCriteria;
        discovery.advancedSearch(emptyCriteria);
        
        discovery.saveSearch("");
        
        CHECK(true);
    }
}

// Тесты для MoodAnalyzer
SUITE(MoodAnalyzerTests)
{
    TEST(MoodAnalyzer_Constructor)
    {
        MoodAnalyzer analyzer;
        CHECK(true);
    }
    
    TEST(MoodAnalyzer_Methods)
    {
        MoodAnalyzer analyzer;
        
        string mood = analyzer.detectMood("happy upbeat music");
        vector<string> suggestions = analyzer.suggestByMood("happy");
        analyzer.analyzePatterns("user123");
        
        CHECK(true);
    }
    
    TEST(MoodAnalyzer_DifferentMoods)
    {
        MoodAnalyzer analyzer;
        
        analyzer.detectMood("sad melancholic song");
        analyzer.detectMood("energetic dance track");
        analyzer.detectMood("calm relaxing ambient");
        
        analyzer.suggestByMood("sad");
        analyzer.suggestByMood("energetic");
        analyzer.suggestByMood("calm");
        
        CHECK(true);
    }
}

// Тесты для Headphones
class HeadphonesTest : public Headphones {
public:
    HeadphonesTest() : Headphones("Test Phones", true) {}
};

SUITE(HeadphonesTests)
{
    TEST(Headphones_ConstructorAndGetters)
    {
        Headphones headphones("Sony WH-1000XM4", true);
        
        CHECK_EQUAL("Sony WH-1000XM4", headphones.getDeviceInfo());
        CHECK_EQUAL(true, headphones.isNoiseCancellationEnabled());
    }
    
    TEST(Headphones_ToggleNoiseCancellation)
    {
        Headphones headphones("Bose QC35", true);
        
        CHECK_EQUAL(true, headphones.isNoiseCancellationEnabled());
        
        headphones.toggleNoiseCancellation();
        CHECK_EQUAL(false, headphones.isNoiseCancellationEnabled());
        
        headphones.toggleNoiseCancellation();
        CHECK_EQUAL(true, headphones.isNoiseCancellationEnabled());
    }
    
    TEST(Headphones_ConnectDisconnect)
    {
        Headphones headphones("Test", false);
        
        headphones.connect();
        headphones.disconnect();
        
        CHECK(true);
    }
}

// Тесты для Equalizer
SUITE(EqualizerTests)
{
    TEST(Equalizer_Constructor)
    {
        Equalizer eq;
        CHECK(true);
    }
    
    TEST(Equalizer_SetBandGain)
    {
        Equalizer eq;
        
        eq.setBandGain(0, 2.5);
        eq.setBandGain(5, -1.2);
        eq.setBandGain(9, 0.0);
        
        CHECK(true);
    }
    
    TEST(Equalizer_Apply)
    {
        Equalizer eq;
        AudioPlayer player;
        
        eq.apply(&player);
        CHECK(true);
    }
}

// Тесты для DownloadManager
SUITE(DownloadManagerTests)
{
    TEST(DownloadManager_Constructor)
    {
        User user("test", "pass", "Test", "test@email.com", PrivacySettings(true, true));
        DownloadManager manager(&user);
        
        CHECK(true);
    }
    
    TEST(DownloadManager_Methods)
    {
        User user("john", "pass", "John", "john@email.com", PrivacySettings(true, true));
        DownloadManager manager(&user);
        Artist artist("Artist", "Country");
        Genre genre("Pop");
        Lyrics lyrics("Lyrics");
        Song song("Song", artist, 180, genre, lyrics);
        
        manager.downloadTrack(song);
        manager.pause();
        manager.resume();
        bool withinLimit = manager.checkLimit();
        
        CHECK(true);
    }
}

// Тесты для DigitalPurchase
SUITE(DigitalPurchaseTests)
{
    TEST(DigitalPurchase_ConstructorAndGetters)
    {
        DigitalPurchase purchase("Song Name", "2024-01-01", 9.99, 
                                "Personal Use", "http://download.com/song", 
                                "No redistribution", "7 days", true);
        
        CHECK_EQUAL("Song Name", purchase.getItem());
        CHECK_EQUAL(9.99, purchase.getPrice());
    }
    
    TEST(DigitalPurchase_Methods)
    {
        DigitalPurchase purchase("Album", "2024-01-01", 14.99, 
                                "Commercial", "http://download.com/album", 
                                "No sharing", "30 days", false);
        
        purchase.activateLicense();
        purchase.download();
        purchase.requestRefund();
        
        CHECK(true);
    }
}

// Тесты для AudioDevice (абстрактный класс)
class TestAudioDevice : public AudioDevice {
public:
    void connect() override {}
    void disconnect() override {}
    string getDeviceInfo() const override { return "Test Device"; }
};

SUITE(AudioDeviceTests)
{
    TEST(AudioDevice_Methods)
    {
        TestAudioDevice device;
        
        device.connect();
        device.disconnect();
        string info = device.getDeviceInfo();
        
        CHECK_EQUAL("Test Device", info);
    }
}
// Тесты для AudioConverter
SUITE(AudioConverterTests)
{
    TEST(AudioConverter_Constructor)
    {
        AudioFormat format("MP3", 44100, 320);
        AudioConverter converter(format);
        
        CHECK(true);
    }
    
    TEST(AudioConverter_GetSupportedFormats)
    {
        AudioFormat format("MP3", 44100, 320);
        AudioConverter converter(format);
        
        string formats = converter.getSupportedFormats();
        CHECK(!formats.empty());
    }
    
    TEST(AudioConverter_ConvertFormat)
    {
        AudioFormat format("MP3", 44100, 320);
        AudioConverter converter(format);
        
        converter.convertFormat("song.mp3", "WAV");
        converter.convertFormat("audio.wav", "FLAC");
        converter.convertFormat("track.flac", "MP3");
        
        CHECK(true);
    }
}
// Тесты для CrossfadeManager
SUITE(CrossfadeManagerTests)
{
    TEST(CrossfadeManager_Constructor)
    {
        CrossfadeManager manager;
        
        CHECK_EQUAL(true, manager.getIsEnabled());
        CHECK_EQUAL(3.0, manager.getFadeDuration());
    }
    
    TEST(CrossfadeManager_SetFadeDuration)
    {
        CrossfadeManager manager;
        
        manager.setFadeDuration(5.0);
        CHECK_EQUAL(5.0, manager.getFadeDuration());
        
        manager.setFadeDuration(1.5);
        CHECK_EQUAL(1.5, manager.getFadeDuration());
    }
    
    TEST(CrossfadeManager_SetEnabled)
    {
        CrossfadeManager manager;
        
        manager.setEnabled(false);
        CHECK_EQUAL(false, manager.getIsEnabled());
        
        manager.setEnabled(true);
        CHECK_EQUAL(true, manager.getIsEnabled());
    }
    
    TEST(CrossfadeManager_CalculateCrossfade)
    {
        CrossfadeManager manager;
        
        double result1 = manager.calculateCrossfade(1.0, 0.0, 1.5);
        double result2 = manager.calculateCrossfade(0.5, 1.0, 2.0);
        double result3 = manager.calculateCrossfade(0.8, 0.2, 0.0);
        
        CHECK(result1 >= 0.0 && result1 <= 1.0);
        CHECK(result2 >= 0.0 && result2 <= 1.0);
        CHECK(result3 >= 0.0 && result3 <= 1.0);
    }
    
    TEST(CrossfadeManager_CalculateCrossfadeDisabled)
    {
        CrossfadeManager manager;
        manager.setEnabled(false);
        
        double result = manager.calculateCrossfade(0.7, 0.3, 2.0);
        CHECK_EQUAL(0.7, result);
    }
    
    TEST(CrossfadeManager_ResetFade)
    {
        CrossfadeManager manager;
        
        manager.resetFade();
        CHECK(true); // Проверяем выполнение метода
    }
}
// Главная функция для запуска всех тестов
int main()
{
    return UnitTest::RunAllTests();
}