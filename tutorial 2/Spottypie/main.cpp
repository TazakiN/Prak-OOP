#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "User.h"
#include "ArtistUser.h"
#include "PremiumUser.h"

int main()
{
    // **User**
    printf("**User**\n");
    User user1("A");
    user1.addFavouriteMusic("Starship - Nicki Minaj");
    user1.addFavouriteMusic("To Be Human - Sia, Labrinth");
    user1.viewMusicList();
    printf("Jumlah user: %d\n", User::getNumOfUser());

    // **ArtistUser**
    printf("\n**ArtistUser**\n");
    ArtistUser artistUser1("B");
    artistUser1.uploadMusic("Loyal - Chris Brown, Lil Wayne, Tyga");
    artistUser1.uploadMusic("Despacito - Luis Fonsi, Daddy Yankee");
    artistUser1.viewUploadedMusicList();
    printf("Jumlah artist user: %d\n", ArtistUser::getNumOfArtist());

    // **PremiumUser**
    printf("\n**PremiumUser**\n");
    PremiumUser premiumUser1("C");
    premiumUser1.activatePremium();
    premiumUser1.downloadMusic("Shape of You - Ed Sheeran");
    premiumUser1.downloadMusic("Perfect - Ed Sheeran");
    premiumUser1.inactivatePremium();
    premiumUser1.downloadMusic("Bad Guy - Billie Eilish");
    printf("Jumlah musik yang didownload: %d\n", premiumUser1.getNumOfMusicDownloaded());

    // Destructor
    printf("\n**Destructor**\n");
    {
        User user2("D");
        ArtistUser artistUser2("E");
        PremiumUser premiumUser2("F");
    }

    return 0;
}
