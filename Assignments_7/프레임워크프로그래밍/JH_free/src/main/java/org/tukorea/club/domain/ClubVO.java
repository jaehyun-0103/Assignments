package org.tukorea.club.domain;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class ClubVO {
    private Integer clubId;
    private String clubName;
    private String description;
    private String category;
    private Integer capacity;
    private String location;
    private String meetingDate;
    private String venue;
    private Integer leaderId;
}
