| #  | Класс                   | Поля | Методы | Ассоциации                                       |
|----|-------------------------|------|--------|--------------------------------------------------|
| 1  | User                    | 6    | 9      | 3→ UserProfile, UserAchievement, FriendSystem    |
| 2  | UserProfile             | 4    | 2      | 1→ PrivacySettings                               |
| 3  | UserAchievements        | 2    | 1      |                                                  |
| 4  | FriendSystem            | 1    | 3      |                                                  |
| 5  | SecurityManager         | 2    | 2      |                                                  |
| 6  | ListeningHistory        | 1    | 3      | 1→ Song                                          |
| 7  | NotificationSystem      | 2    | 3      | 1→ User                                          |
| 8  | PrivacySettings         | 2    | 1      |                                                  |
| 9  | Song                    | 5    | 6      | 3→ Artist, Genre, Lyrics                         |
| 10 | Album                   | 3    | 5      | 2→ Song, Artist                                  |
| 11 | Artist                  | 2    | 2      |                                                  |
| 12 | Playlist                | 3    | 9      | 2→ Song, User                                    |
| 13 | Genre                   | 1    | 2      |                                                  |
| 14 | Lyrics                  | 1    | 1      |                                                  |
| 15 | AudioFormat             | 3    | 3      |                                                  |
| 16 | PhysicalMedia           | 5    | 5      | 1→ AudioFormat                                   |
| 17 | VinylRecord             | 1    | 1      |                                                  |
| 18 | CassetteTape            | 1    | 1      |                                                  |
| 19 | CompactDisc             | 1    | 1      |                                                  |
| 20 | _MusicMetadata          | 15   | 9      | 3→ Song, Copyright, AudioQuality                 |
| 21 | AudioQuality            | 2    | 2      |                                                  |
| 22 | Copyright               | 3    | 4      |                                                  |
| 23 | Podcast                 | 2    | 3      |                                                  |
| 24 | Audiobook               | 4    | 4      |                                                  |
| 25 | MusicVideo              | 3    | 3      |                                                  |
| 26 | LiveRecording           | 3    | 3      |                                                  |
| 27 | Remix                   | 4    | 4      | 1→ SoundEffect                                   |
| 28 | SoundEffect             | 10   | 3      |                                                  |
| 29 | Concert                 | 5    | 2      | 1→ Artist                                        |
| 30 | DigitalMedia            | 4    | 4      |                                                  |
| 31 | AudioPlayer             | 3    | 5      |                                                  |
| 32 | PlaybackController      | 1    | 4      | 1→ AudioPlayer                                   |
| 33 | Equalizer               | 1    | 2      | 1→ AudioPlayer                                   |
| 34 | StreamManager           | 1    | 3      |                                                  |
| 35 | CrossfadeManager        | 3    | 6      |                                                  |
| 36 | VolumeNormalizer        | 2    | 4      | 1→ AudioPlayer                                   |
| 37 | AudioConverter          | 3    | 3      | 1→ AudioFormat                                   |
| 38 | DownloadManager         | 6    | 4      | 2→ Song, User                                    |
| 39 | AudioDevices            | 0    | 3      |                                                  |
| 40 | WirelessSpeaker         | 3    | 3      |                                                  |
| 41 | Headphones              | 2    | 3      |                                                  |
| 42 | SoundSystem             | 2    | 3      |                                                  |
| 43 | MusicStore              | 12   | 4      | 4→ User, Song, DigitalPurchase, PhysicalMediaOrder |
| 44 | ShoppingCart            | 11   | 4      | 3→ DigitalPurchase, PhysicalMediaOrder, User     |
| 45 | DigitalPurchase         | 8    | 5      |                                                  |
| 46 | PhysicalMediaOrder      | 11   | 6      |                                                  |
| 47 | RecommendationSystem    | 10   | 3      | 1→ User                                          |
| 48 | MusicDiscovery          | 8    | 3      |                                                  |
| 49 | MoodAnalyzer            | 7    | 3      |                                                  |
| 50 | PlaylistGenerator       | 8    | 3      |                                                  |
 Итоговые подсчёты

    Всего классов: 50 (+12 исключений = 62)

    Всего полей: 203

    Всего методов: 175

    Всего ассоциаций: 33
